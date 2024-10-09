#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to hold the fetched data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write the fetched data into memory
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;  // Out of memory!
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0;  // Null-terminate the string
    return realsize;
}

int main(void) {
    CURL *curl;
    CURLcode res;

    // Initialize a memory structure to hold the fetched data
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  // Initial allocation
    chunk.size = 0;            // No data at this point

    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        // Set the URL to fetch data from (e.g., NSE stock data)
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.nseindia.com/api/option-chain-indices");  // Adjust the URL as needed

        // Set the callback function to write the data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        
        // Set options for handling HTTP headers (optional, depending on the endpoint)
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: Your User Agent Here");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        // Perform the request, and check for errors
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Successfully fetched data; write it to a file
            FILE *file = fopen("nse_data.json", "w");
            if (file) {
                fwrite(chunk.memory, sizeof(char), chunk.size, file);
                fclose(file);
                printf("Data successfully written to nse_data.json\n");
            } else {
                printf("Could not open file for writing\n");
            }
        }

        // Cleanup
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        free(chunk.memory);
    }

    curl_global_cleanup();
    return 0;
}
