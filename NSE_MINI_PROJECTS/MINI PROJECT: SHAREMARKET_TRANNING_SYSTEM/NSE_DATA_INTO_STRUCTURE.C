#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Function to create a new linked list node
StockNode *createNode(StockData stock)
{
    StockNode *newNode = (StockNode *)malloc(sizeof(StockNode));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->stock = stock;
    newNode->next = NULL;
    return newNode;
}

// Function to read stock data from a file and populate a linked list
StockNode *readStockDataFromFile(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    StockNode *head = NULL, *tail = NULL;
    char line[1024]; // Adjust size as needed

    while (fgets(line, sizeof(line), file))
    {
        StockData stock;

        // Example parsing logic (modify according to your file format)
        if (sscanf(line,
                   "%9[^,],%99[^,],%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                   stock.info.symbol,
                   stock.info.companyName,
                   &stock.priceInfo.lastPrice,
                   &stock.priceInfo.change,
                   &stock.priceInfo.previousClose,
                   &stock.priceInfo.open,
                   &stock.priceInfo.lowerCP,
                   &stock.priceInfo.upperCP,
                   &stock.metadata.pdSectorPe,
                   &stock.metadata.pdSymbolPe,
                   stock.metadata.lastUpdateTime,
                   stock.info.industry,
                   &stock.priceInfo.intraDayHighLow.min,
                   &stock.priceInfo.intraDayHighLow.max,
                   &stock.priceInfo.intraDayHighLow.value,
                   &stock.priceInfo.weekHighLow.min,
                   &stock.priceInfo.weekHighLow.max,
                   stock.priceInfo.weekHighLow.minDate,
                   stock.priceInfo.weekHighLow.maxDate,
                   &stock.priceInfo.weekHighLow.value) != 17)
        { // Check number of parsed items
            printf("Error parsing line: %s\n", line);
            continue; // Skip this line if parsing fails
        }

        // Add the stock to the linked list
        StockNode *newNode = createNode(stock);
        if (head == NULL)
        {
            head = newNode; // First node
            tail = newNode;
        }
        else
        {
            tail->next = newNode; // Append to the list
            tail = newNode;
        }
    }

    fclose(file);
    return head;
}

// Function to print the stock list
void printStockList(StockNode *head)
{
    StockNode *current = head;
    while (current != NULL)
    {
        printf("Symbol: %s, Company Name: %s, Last Price: %.2f\n",
               current->stock.info.symbol,
               current->stock.info.companyName,
               current->stock.priceInfo.lastPrice);
        current = current->next;
    }
}

// Main function
int main()
{
    const char *filename = "NSE_DATA.txt"; // Replace with your file name
    StockNode *stockList = readStockDataFromFile(filename);

    // Print the stock list
    printStockList(stockList);

    // Free the linked list
    StockNode *temp;
    while (stockList != NULL)
    {
        temp = stockList;
        stockList = stockList->next;
        free(temp);
    }

    return 0;
}
