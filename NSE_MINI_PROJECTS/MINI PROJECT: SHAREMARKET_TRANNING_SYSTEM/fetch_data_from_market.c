#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h> // for sleep()

struct string
{
    char *ptr;
    size_t len;
};

void init_string(struct string *s)
{
    s->len = 0;
    s->ptr = malloc(s->len + 1);
    if (s->ptr == NULL)
    {
        fprintf(stderr, "malloc() failed\n");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
    size_t new_len = s->len + size * nmemb;
    s->ptr = realloc(s->ptr, new_len + 1);
    if (s->ptr == NULL)
    {
        fprintf(stderr, "realloc() failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr + s->len, ptr, size * nmemb);
    s->len = new_len;
    s->ptr[s->len] = '\0';

    return size * nmemb;
}

// Function to fetch data for a given stock symbol
void fetch_data_for_symbol(const char *symbol, FILE *fp_NSE)
{
    CURL *curl;
    CURLcode res;

    struct string s;
    init_string(&s);

    curl = curl_easy_init();
    if (curl)
    {
        char url[256];
        snprintf(url, sizeof(url), "https://www.nseindia.com/api/quote-equity?symbol=%s", symbol);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed for %s: %s\n", symbol, curl_easy_strerror(res));
        }
        else
        {
            fprintf(fp_NSE, "Data for %s:\n%s\n\n", symbol, s.ptr);
        }

        curl_easy_cleanup(curl);
        free(s.ptr);
    }
}

int main(void)
{
    CURL *curl;
    CURLcode res;

    // Open file to write the stock data
    FILE *fp_NSE = fopen("NSE_DATA.txt", "w");
    if (fp_NSE == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);

    // List of stock symbols to fetch data for
    // This list should ideally be fetched dynamically from a CSV or NSE API
    const char *stock_symbols[] = {"TCS", "INFY", "RELIANCE", "ONGC", "ICICIBANK", "SBIN", "ITC", "BANDHANBNK", "BSE", "USHAMART", "TATASTEEL"};
    int num_symbols = sizeof(stock_symbols) / sizeof(stock_symbols[0]);

    for (int i = 0; i < num_symbols; ++i)
    {
        printf("Fetching data for symbol: %s\n", stock_symbols[i]);
        fetch_data_for_symbol(stock_symbols[i], fp_NSE);
        usleep(100);  // Add delay to prevent getting blocked by NSE
    }

    fclose(fp_NSE);
    curl_global_cleanup();

    return 0;
}
