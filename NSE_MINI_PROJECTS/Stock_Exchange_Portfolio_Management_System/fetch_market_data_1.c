#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

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

int main(void)
{
    CURL *curl;
    CURLcode res;
    FILE *fp_NSE = fopen("NSE_DATA.txt", "w");
    if (fp_NSE == NULL)
    {
        perror("fopen");
        return EXIT_FAILURE;
    }

    struct string s;
    init_string(&s);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl)
    {
        // Set the URL for the NSE Nifty 50 index data
        curl_easy_setopt(curl, CURLOPT_URL, "https://pro.upstox.com/");

        // Set user agent to prevent request blocking
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36");

        // Write response to our custom string structure
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            // Print the data to the console
           printf("%s\n", s.ptr);

            // Write the fetched data to file
            //fprintf(fp_NSE, "%s\n", s.ptr);
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    fclose(fp_NSE);
    free(s.ptr);
    curl_global_cleanup();

    return 0;
}
 