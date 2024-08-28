
#include "header.h"

void logInfo(int line,char *string) {
    FILE *fpSource = NULL;
    char buffer[256];        // Allocate a fixed-size buffer

    snprintf(buffer, sizeof(buffer), "%d: %s\n",line, string);
    fpSource = fopen("logEntry.txt", "a+");
    if (fpSource != NULL) {
        fwrite(buffer, sizeof(char), strlen(buffer), fpSource);
        fclose(fpSource);
    } else {
        printf("Failed to open logEntry.txt\n");
    }
    return;
}

void logError(int line,char *error) {
    FILE *fpError = NULL;
    char buffer[256];         // Allocate a fixed-size buffer

    snprintf(buffer, sizeof(buffer), "%d: %s\n",line, error);
    fpError = fopen("error.txt", "a+");
    if (fpError != NULL) {
        fwrite(buffer, sizeof(char), strlen(buffer), fpError);
        fclose(fpError);
    } else {
        printf("Failed to open error.txt\n");
    }
    return;
}
