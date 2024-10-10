#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

struct StockData {
    char symbol[20];
    double open;
    double dayHigh;
    double dayLow;
    double lastPrice;
    double change;
    double pChange;
    struct StockData *next;
};

// Function to create a new stock node
struct StockData* createStockNode(const char *symbol, double open, double dayHigh, double dayLow, double lastPrice, double change, double pChange) {
    struct StockData *newStock = (struct StockData *)malloc(sizeof(struct StockData));
    if (newStock == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newStock->symbol, symbol, sizeof(newStock->symbol) - 1);
    newStock->symbol[sizeof(newStock->symbol) - 1] = '\0';
    newStock->open = open;
    newStock->dayHigh = dayHigh;
    newStock->dayLow = dayLow;
    newStock->lastPrice = lastPrice;
    newStock->change = change;
    newStock->pChange = pChange;
    newStock->next = NULL;
    return newStock;
}

// Function to insert stock data into linked list
void insertStock(struct StockData **head, const char *symbol, double open, double dayHigh, double dayLow, double lastPrice, double change, double pChange) {
    struct StockData *newStock = createStockNode(symbol, open, dayHigh, dayLow, lastPrice, change, pChange);
    newStock->next = *head;
    *head = newStock;
}

// Function to display stock data in table format
void displayStockData(struct StockData *head) {
    if (head == NULL) {
        printf("No stock data available.\n");
        return;
    }

    printf(BBLACK BLUE"--------------------------------------------------------------------------\n");
    printf("| %-10s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", 
            "Symbol", "Open", "High", "Low", "Last Price", "Change (%)");
    printf("--------------------------------------------------------------------------\n"RESET);

    struct StockData *current = head;
    while (current != NULL) {
        printf(BBLACK RED"| %-10s | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-10.2f |\n", 
                current->symbol, current->open, current->dayHigh, current->dayLow, current->lastPrice, current->pChange);
        current = current->next;
    }
    printf("--------------------------------------------------------------------------\n"RESET);
}

// Helper function to extract a value from JSON-like data
char* extractValue(const char* source, const char* key) {
    char* start = strstr(source, key);
    if (start) {
        start = strchr(start, ':');
        if (start) {
            start++;  // Move past ':'
            while (*start == ' ' || *start == '\"') start++;  // Skip spaces and quotes
            char* end = strchr(start, '\"');  // Find the ending quote
            if (!end) {
                end = strchr(start, ',');  // In case no quotes are used (for numbers)
            }
            if (end) {
                size_t length = end - start;
                char* value = (char*)malloc(length + 1);
                strncpy(value, start, length);
                value[length] = '\0';
                return value;
            }
        }
    }
    return NULL;
}

// Function to parse a line containing stock data in JSON-like format
void parseStockData(char *line, struct StockData **head) {
    char *symbol = extractValue(line, "\"symbol\"");
    char *openStr = extractValue(line, "\"open\"");
    char *dayHighStr = extractValue(line, "\"dayHigh\"");
    char *dayLowStr = extractValue(line, "\"dayLow\"");
    char *lastPriceStr = extractValue(line, "\"lastPrice\"");
    char *changeStr = extractValue(line, "\"change\"");
    char *pChangeStr = extractValue(line, "\"pChange\"");

    if (symbol && openStr && dayHighStr && dayLowStr && lastPriceStr && changeStr && pChangeStr) {
        double open = atof(openStr);
        double dayHigh = atof(dayHighStr);
        double dayLow = atof(dayLowStr);
        double lastPrice = atof(lastPriceStr);
        double change = atof(changeStr);
        double pChange = atof(pChangeStr);

        insertStock(head, symbol, open, dayHigh, dayLow, lastPrice, change, pChange);
    }

    // Free dynamically allocated strings
    free(symbol);
    free(openStr);
    free(dayHighStr);
    free(dayLowStr);
    free(lastPriceStr);
    free(changeStr);
    free(pChangeStr);
}

// Function to read data from a file and insert into linked list
void readDataFromFile(const char *filename, struct StockData **head) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];

    // Read the file line by line and parse stock data
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "\"symbol\"")) {  // Check if the line contains stock data
            parseStockData(line, head);
        }
    }

    fclose(file);
}

int main() {
    struct StockData *head = NULL;

    // Read from the NSE_DATA.txt file (ensure the file is in JSON-like format)
    readDataFromFile("NSE_DATA.txt", &head);

    // Display stock data in table format
    displayStockData(head);

    // Free the linked list (not shown here for brevity)
    return 0;
}
