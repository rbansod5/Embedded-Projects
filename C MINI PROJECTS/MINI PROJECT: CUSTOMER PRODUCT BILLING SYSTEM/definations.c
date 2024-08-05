/***********************************************
 * this files have all functions definations
 ***********************************************
 */

/*****************************************************************
 * @file      definations.c                                      *
 * @author    Rahul Shridhar Bansod                              *
 * @brief     this file manage all function definations          *
 * @version   0.1v                                               *
 * @date      2024-06-06                                         *
 * @copyright Copyright (c) Remiges technologies pvt. Ltd. (2024)*
 *****************************************************************
 */

#include "header.h"      //include predefine libraries
#include "macros.h"      //include some useful macros
#include "structure.h"   //include all required strcture
#include "declaration.h" //include all declaration of function defination
#include "colors.h"      //to give color code to Strings

extern int count;                  // variable is initialized in another file
extern int position;               // variable is initialized in another file
extern customerinfo customer[MAX]; // strcture array is initialized in another file
extern productData Products[MAX];  // strcture array is initialized in another file

/**
 * This Function is to add new customer information
 * it is stores customer name, customer Id, customer
 * contact Number and email address
 */
void addCustomerData(customerinfo customer[], int position)
{
    int customerId, flag = 0;
Lable:
Lable2:
    printf(MAGENTA "Enter Customer Id more than 0:\n" RESET);
    __fpurge(stdin);
    scanf(" %d", &customerId);
    if (customerId == 0)
    {
        printf(RED "Do not Enter ZERO as an Id\n" RESET);
        goto Lable2;
    }
    for (int i = 0; i < MAX; i++)
    {

        if ((customer[i].customerId == customerId))
        {
            printf(RED "Customer with This Id is already present !\n Please add with Different Id\n\n" RESET);
            goto Lable;
        }
    }
    customer[position].customerId = customerId;
    printf(YELLOW "Enter Name of Customer:\n" RESET);
    getchar(); // Clear newline character
    customer[position].name = getString(customer[position].name);
    printf(CYAN "Enter Customer Contact Number:\n" RESET);
    scanf(" %ld", &customer[position].contactNumber);
    printf(GREEN "Enter the email Id:\n" RESET);
    getchar(); // Clear newline character
    customer[position].emailId = getString(customer[position].emailId);
}

/**
 * This function is Design for if Customer Information is not correct
 * then it will be Modify that data accordingly
 */
void editCustomerData(customerinfo customer[], int position)
{
    int customerId, flag = 0, location = 0;
Lable:
Lable2:
    printf(MAGENTA "Enter Customer Id more than 0:\n" RESET);
    __fpurge(stdin);
    scanf(" %d", &customerId);
    if (customerId == 0)
    {
        printf(RED "Do not Enter ZERO as an Id\n" RESET);
        goto Lable2;
    }
    for (int i = 0; i < MAX; i++)
    {

        if ((customer[i].customerId == customerId))
        {
            customer[i].customerId = customerId;
            flag = 1;
            location = i;
            break;
        }
    }
    if (flag == 0)
    {
        printf(RED "Data Not Found\n" RESET);
        goto Lable;
    }
    printf(GREEN " Data Found!\n You can Modify this Data\n" RESET);
    printf(YELLOW "Enter Name of Customer:\n" RESET);
    getchar(); // Clear newline character
    customer[location].name = getString(customer[location].name);
    printf(CYAN "Enter Customer Contact Number:\n" RESET);
    scanf(" %ld", &customer[location].contactNumber);
    printf(GREEN "Enter the email Id:\n" RESET);
    getchar(); // Clear newline character
    customer[location].emailId = getString(customer[location].emailId);
    printf(GREEN "Data Saved Successfuly\n" RESET);
}

/**
 * Function to delete customer data
 */
void deleteCustomerData(customerinfo customer[], int *count)
{
    int customerId;
    int found = 0;

    printf(MAGENTA "Enter Customer Id to delete:\n" RESET);
    scanf(" %d", &customerId);

    for (int i = 0; i < *count; i++)
    {
        if (customer[i].customerId == customerId)
        {
            found = 1;

            for (int j = i; j < *count - 1; j++)
            {
                customer[j] = customer[j + 1]; // Shift all elements to the left
            }
            (*count)--;
            printf(GREEN "Customer with ID %d deleted successfully.\n" RESET, customerId);
            break;
        }
    }

    if (!found)
    {
        printf(RED "Customer with ID %d not found.\n" RESET, customerId);
    }
}

/**
 * This Function purpose for loadding the binary data from text/bin file to store that
 * data into strcture variables
 */
void loadCustomerData(customerinfo customer[], int *count)
{
    FILE *file = fopen("Customer_data.bin", "rb");
    if (file == NULL)
    {
        printf(RED "Customer_data not existing, Starting fresh.\n" RESET);
        return;
    }

    int i = 0;
    while (i < MAX && fread(&customer[i].customerId, sizeof(int), 1, file) == 1)
    {
        fread(&customer[i].contactNumber, sizeof(long int), 1, file);

        int nameLen;
        fread(&nameLen, sizeof(int), 1, file);
        customer[i].name = (char *)malloc(nameLen * sizeof(char));
        fread(customer[i].name, sizeof(char), nameLen, file);

        int emailLen;
        fread(&emailLen, sizeof(int), 1, file);
        customer[i].emailId = (char *)malloc(emailLen * sizeof(char));
        fread(customer[i].emailId, sizeof(char), emailLen, file);

        i++;
    }

    *count = i; // put i value in count
    // passing address because of not returning any value
    fclose(file);
}

/**
 * This function purpose is for store Customer strcture data into binary file
 */
void saveCustomerData(customerinfo customer[], int count)
{
    FILE *file = fopen("Customer_data.bin", "wb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        int nameLen = strlen(customer[i].name) + 1; // +1 for null terminator
        int emailLen = strlen(customer[i].emailId) + 1;

        fwrite(&customer[i].customerId, sizeof(int), 1, file);
        fwrite(&customer[i].contactNumber, sizeof(long int), 1, file);
        fwrite(&nameLen, sizeof(int), 1, file);
        fwrite(customer[i].name, sizeof(char), nameLen, file);
        fwrite(&emailLen, sizeof(int), 1, file);
        fwrite(customer[i].emailId, sizeof(char), emailLen, file);
    }
    fclose(file);
}

/**
 * This Function is design for to display customer information
 * on console, data it fetch from binary file.
 */
void displayCustomerData(customerinfo customer[], int position)
{
    STAR_LINE(12)
    NEW_LINE
    for (int i = 0; i < position; i++)
    {
        printf(BBLACK CYAN "Customer Id = %d  \n", customer[i].customerId);
        printf("Name of Customer = %s\n", customer[i].name);
        printf("Customer Contact Number = %ld\n", customer[i].contactNumber);
        printf("Email Id = %s\n\n" RESET, customer[i].emailId);
    }
    NEW_LINE
    STAR_LINE(12)
    NEW_LINE
}

/**
 * @brief This Function is design for add bill binary data which have customer details,
 *        product details and total price
 * @param bill is a strcture array of customer Bill
 * @param billPosition is a position of array which have saved data/required data
 */
void addBillData(customerBill bill[], int billPosition)
{
    int customerId, ProductsID, productQunatity, flag = 0, found = 1;
    char choice;
Lable:
    printf(YELLOW "Enter Customer Id for billing:\n" RESET);
    __fpurge(stdin);
    scanf("%d", &customerId);

    // Find and copy customer information
    for (int i = 0; i < count; i++)
    {
        if (customer[i].customerId == customerId)
        {
            bill[billPosition].ConsumerData.customerId = customerId;
            int nameLen = strlen(customer[i].name) + 1;
            int emailLen = strlen(customer[i].emailId) + 1;

            bill[billPosition].ConsumerData.name = (char *)malloc(nameLen * sizeof(char));
            strcpy(bill[billPosition].ConsumerData.name, customer[i].name);
            printf(GREEN "Customer Name : %s\n" RESET, bill[billPosition].ConsumerData.name);

            bill[billPosition].ConsumerData.contactNumber = customer[i].contactNumber;
            printf(BLUE "contactNumber = %ld\n" RESET, bill[billPosition].ConsumerData.contactNumber);

            bill[billPosition].ConsumerData.emailId = (char *)malloc(emailLen * sizeof(char));
            strcpy(bill[billPosition].ConsumerData.emailId, customer[i].emailId);
            printf(CYAN "Customer email Id =%s\n" RESET, bill[billPosition].ConsumerData.emailId);
            found = 0;
            break;
        }
    }
    if (found == 1)
    {
        printf(RED "Customer Id not found\n\n" RESET);
        goto Lable;
        return;
    }

    printf("\n\n");
    for (int i = 0; i < MAX; i++)
    {
        displayProducts(Products, position);
        printf(YELLOW "Enter the  Product Id to purchase a product:(Enter 0 goto main manu)\n\n" RESET);
        __fpurge(stdin);
        scanf("%d", &ProductsID);
        if (ProductsID == 0)
        {
            break;
        }
        ProductsID = ProductsID - 1;
        bill[billPosition].products[i].productId = Products[ProductsID].productId;
        int productNameLen = strlen(Products[ProductsID].productName) + 1;
        bill[billPosition].products[i].productName = (char *)malloc(productNameLen * sizeof(char));
        strcpy(bill[billPosition].products[i].productName, Products[ProductsID].productName);
        printf(BLUE "product Name %s:\n" RESET, bill[billPosition].products[i].productName);
    lable:
        printf(GREEN "Enter Quantity of Products(Enter 0 goto main manu)\n" RESET);
        scanf("%d", &productQunatity);
        if (productQunatity == 0)
        {
            break;
        }
        bill[billPosition].products[i].productQuantity = productQunatity;

        int Qunatity = Products[ProductsID].productQuantity - productQunatity;
        if (Qunatity > 0)
        {
            Products[ProductsID].productQuantity = Qunatity;
        }
        if (Qunatity < 0)
        {
            printf(RED "Please Enter valid Quntity stock doesnt have much Quantity\n" RESET);
            goto lable;
        }
        bill[billPosition].products[i].productPrice = Products[ProductsID].productPrice * productQunatity;

        saveProductDetails(Products, position);
        printf(GREEN "Product Total price is %0.2f\u20B9\n" RESET, bill[billPosition].products[i].productPrice);

        int flag = 1;
        if (flag)
        {
            printf(RED " do you want to continue shopping y/n \n" RESET);
            __fpurge(stdin);
            scanf("%c", &choice);
            flag = 0;
            if (choice == 'y' || choice == 'Y')
            {
                continue;
            }
            if (choice == 'n' || choice == 'N')
            {
                break;
            }
        }
    }
    for (int i = 0; i < billPosition; i++)
    {
        // printf("Product Total price is %0.2f\n", bill[billPosition].products[i].productPrice);
        bill[billPosition].totalBill += bill[billPosition].products[i].productPrice;
    }
    printf(BLUE "total bill %0.2f \u20B9\n" RESET, bill[billPosition].totalBill);
    printf(BBLACK RED "Generating your bill...\n" RESET);
    displayBill(bill, position);
}

/**
 * This Function is design for add bill Text data which have customer details,
 * product details and total price
 */
void addBillDataText(customerBill bill[], int billPosition)
{
    int customerId, ProductsID, productQunatity, flag = 0, found = 1;
    char choice;
Lable:
    printf(YELLOW "Enter Customer Id for billing:(0 for Main Menu)\n" RESET);
    __fpurge(stdin);
    scanf("%d", &customerId);
    if (customerId == 0)
    {
        return;
    }
    // Find and copy customer information
    for (int i = 0; i < count; i++)
    {
        if (customer[i].customerId == customerId)
        {
            bill[billPosition].ConsumerData.customerId = customerId;
            int nameLen = strlen(customer[i].name) + 1;
            int emailLen = strlen(customer[i].emailId) + 1;

            bill[billPosition].ConsumerData.name = (char *)malloc(nameLen * sizeof(char));
            strcpy(bill[billPosition].ConsumerData.name, customer[i].name);
            printf(GREEN "Customer Name : %s\n" RESET, bill[billPosition].ConsumerData.name);

            bill[billPosition].ConsumerData.contactNumber = customer[i].contactNumber;
            printf(BLUE "contactNumber = %ld\n" RESET, bill[billPosition].ConsumerData.contactNumber);

            bill[billPosition].ConsumerData.emailId = (char *)malloc(emailLen * sizeof(char));
            strcpy(bill[billPosition].ConsumerData.emailId, customer[i].emailId);
            printf(CYAN "Customer email Id =%s\n" RESET, bill[billPosition].ConsumerData.emailId);
            found = 0;
            break;
        }
    }
    if (found == 1)
    {
        printf(RED "Customer Id not found\n\n" RESET);
        goto Lable;
        return;
    }

    printf("\n\n");
    // displayProducts(Products, position);
    for (int i = 0; i < MAX; i++)
    {
        displayProducts(Products, position);
        printf(YELLOW "Enter the  Product Id to purchase a product:(Enter 0 goto main manu)\n\n" RESET);
        __fpurge(stdin);
        scanf("%d", &ProductsID);
        if (ProductsID == 0)
        {
            break;
        }
        ProductsID = ProductsID - 1;
        bill[billPosition].products[i].productId = Products[ProductsID].productId;
        int productNameLen = strlen(Products[ProductsID].productName) + 1;
        bill[billPosition].products[i].productName = (char *)malloc(productNameLen * sizeof(char));
        strcpy(bill[billPosition].products[i].productName, Products[ProductsID].productName);
        printf(BLUE "product Name %s:\n" RESET, bill[billPosition].products[i].productName);
    lable:
        printf(GREEN "Enter Quantity of Products(Enter 0 goto main manu)\n" RESET);
        scanf("%d", &productQunatity);
        if (productQunatity == 0)
        {
            break;
        }
        bill[billPosition].products[i].productQuantity = productQunatity;

        int Qunatity = Products[ProductsID].productQuantity - productQunatity;
        if (Qunatity > 0)
        {
            Products[ProductsID].productQuantity = Qunatity;
        }
        if (Qunatity < 0)
        {
            printf(RED "Please Enter valid Quntity stock doesnt have much Quantity\n" RESET);
            goto lable;
        }
        bill[billPosition].products[i].productPrice = Products[ProductsID].productPrice * productQunatity;

        // saveProductDetails(Products, position);
        storeProductDataToFile(Products, position); // store data into text file
        printf(GREEN "Product Total price is %0.2f \u20B9\n" RESET, bill[billPosition].products[i].productPrice);

        int flag = 1;
        if (flag)
        {
            printf(RED " do you want to continue shopping y/n \n" RESET);
            __fpurge(stdin);
            scanf("%c", &choice);
            flag = 0;
            if (choice == 'y' || choice == 'Y')
            {
                continue;
            }
            if (choice == 'n' || choice == 'N')
            {
                break;
            }
        }
    }
    for (int i = 0; i < billPosition; i++)
    {
        // printf("Product Total price is %0.2f\n", bill[billPosition].products[i].productPrice);
        bill[billPosition].totalBill += bill[billPosition].products[i].productPrice;
    }
    printf(BLUE "total bill %0.2f \n" RESET, bill[billPosition].totalBill);
    printf(GREEN "Bill added successfully\n" RESET);

    printf(WHITE "System Genetaring your bill\n" RESET);
    printf(YELLOW "please wait...\n" RESET);
}

/**
 * This Function is display bill strcture data on console
 */
void displayBill(customerBill bill[], int position)
{
    saveBillingData(bill, position);
    printf(YELLOW "Customer Name %s:\n" RESET, bill[position].ConsumerData.name);
    STAR_LINE(position)
    NEW_LINE
    for (int j = 0; j < position; j++)
    {
        if (bill[position].products[j].productName == NULL)
        {
            break;
        }
        printf(BBLACK "\n");
        printf(MAGENTA "product Name : %s\n", bill[position].products[j].productName);
        printf("product Qunatity : %d\n", bill[position].products[j].productQuantity);
        printf("Product Price %0.2f\n" RESET, bill[position].products[j].productPrice);
    }
    printf(BBLACK CYAN "Total bill %0.2f\u20B9\n", bill[position].totalBill);
    printf(BBLACK "Current Time: %s\n" RESET, currentTime());
    NEW_LINE
    STAR_LINE(position)
    NEW_LINE
}

/**
 * This Function is to design for save bill data into text file in present folder
 */
void saveBillingData(customerBill bill[], int position)
{
    FILE *file = fopen("billing_data.txt", "a"); // Open file in append mode
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "********************************************************\n");
    fprintf(file, "Customer Id: %d\n", bill[position].ConsumerData.customerId);
    fprintf(file, "Customer Name: %s\n", bill[position].ConsumerData.name);
    fprintf(file, "Customer Contact Number: %ld\n", bill[position].ConsumerData.contactNumber);
    fprintf(file, "Customer Email: %s\n", bill[position].ConsumerData.emailId);

    // Save product details
    for (int i = 0; i < MAX; i++)
    {
        if (bill[position].products[i].productName == NULL)
        {
            break;
        }
        fprintf(file, "Product Name: %s\n", bill[position].products[i].productName);
        fprintf(file, "product Qunatity : %d\n", bill[position].products[i].productQuantity);
        fprintf(file, "Product Price: %.2f\n", bill[position].products[i].productPrice);
    }
    fprintf(file, "\n");
    fprintf(file, "Total Bill: %.2f\u20B9\n", bill[position].totalBill);
    fprintf(file, "Current Time: %s\n\n", currentTime());
    fprintf(file, "********************************************************\n");
    fprintf(file, "\n");
    printf(GREEN "Bill added successfully\n" RESET);
    fclose(file);
}

/**
 * to get string using dynamic memory allocation
 */
char *getString(char *string)
{
    int count = 0;
    char character;
    string = (char *)calloc(1, sizeof(char)); // allocate 1 byte memory
    while ((character = getchar()) != '\n')
    {
        string = realloc(string, count + 2); // +2 to account for '\0'
        string[count++] = character;
    }
    string[count] = '\0';
    return string;
}

/**
 * to get a string which have real time details like Date and Time
 */
char *currentTime()
{
    // Create a time_t variable to store the current time
    time_t currentTime;

    // Get the current time
    time(&currentTime);

    // Convert the time to local time
    struct tm *localTime = localtime(&currentTime);

    // Print the current date and time
    char *realTime = asctime(localTime);
    return realTime;
}

/**
 * to display all products which store in a productData strcture
 */
void displayProducts(productData products[], int numProducts)
{
    STAR_LINE(13)
    NEW_LINE
    for (int i = 0; i < numProducts; i++)
    {
        printf(BBLACK GREEN "| Product ID : %-5d| Product Name : %-20s| Product Quantity : %-5d| Product Price : %.2f \u20B9\n" RESET,
               products[i].productId, products[i].productName,
               products[i].productQuantity, products[i].productPrice);
    }
    NEW_LINE
    STAR_LINE(13)
    NEW_LINE
}

/**
 * This Function is design for to add product description data into binary file
 */
void addProductDetails(productData product[], int position)
{
    int productId;
Lable:
    printf(CYAN "\n Enter the Product Id:(Enter 0 for Main Menu)" RESET);
    __fpurge(stdin);
    scanf("%d", &productId);
    if (productId == 0)
    {
        return;
    }
    for (int i = 0; i < MAX; i++)
    {
        if (product[i].productId == productId)
        {
            printf(RED "Product Id id already Exist\n please enter new Id\n Press 0 for Exit\n" RESET);
            goto Lable;
        }
    }
    product[position].productId = productId;
    printf(YELLOW "\n Enter Product Name: " RESET);
    getchar();
    product[position].productName = getString(product[position].productName);
    printf(BLUE "\n Enter the Product Quantity: " RESET);
    scanf("%d", &product[position].productQuantity);
    printf(GREEN "\n Enter the Product Price: " RESET);
    scanf("%f ", &product[position].productPrice);
}

/**
 * This Function is design to edit product data
 */
void editProductDetails(productData product[], int position)
{
    int productId, found = 0, location = 0;
Lable:
    printf(CYAN "\n Enter the Product Id(Enter 0 to return Main Menu): " RESET);
    __fpurge(stdin);
    scanf("%d", &productId);
    if (productId == 0)
    {
        return;
    }
    for (int i = 0; i < MAX; i++)
    {
        if (product[i].productId == productId)
        {
            printf(GREEN " Product Id Found" RESET);
            product[i].productId = productId;
            location = i;
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf(RED "Data Not Found!, please try again\n" RESET);
        goto Lable;
    }

    // printf(CYAN "\n Enter the Product Id: ");
    // scanf("%d", &product[location].productId);
    printf(YELLOW "\n Enter Product Name: " RESET);
    getchar();
    product[location].productName = getString(product[location].productName);
    printf(BLUE "\n Enter the Product Quantity: " RESET);
    scanf("%d", &product[location].productQuantity);
    printf(GREEN "\n Enter the Product Price: " RESET);
    scanf("%f", &product[location].productPrice);
}

/**
 * This Function is design to Delete product data
 */
void deleteProductDetails(productData product[], int *position)
{
    int productId, found = 0;

    printf(BBLACK CYAN "\n Enter the Product Id to delete: " RESET);
    __fpurge(stdin); // use __fpurge or equivalent on platforms that support it
    scanf("%d", &productId);

    for (int i = 0; i < *position; i++)
    {
        if (product[i].productId == productId)
        {
            found = 1;
            // Free the memory allocated for productName
            free(product[i].productName);

            // Shift all elements to the left
            for (int j = i; j < *position - 1; j++)
            {
                product[j] = product[j + 1];
            }
            (*position)--;
            printf(GREEN "\n Product with ID %d deleted successfully.\n" RESET, productId);
            break;
        }
    }
    if (!found)
    {
        printf(RED "\n Product with ID %d not found.\n" RESET, productId);
    }
}

/**
 * sort product data
 */
void sortProductData(productData product[], int position)
{
    productData temp;
    for (int i = 0; i < position - 1; i++)
    {
        for (int j = 0; j < position - i - 1; j++)
        {
            if (product[j].productId > product[j + 1].productId)
            {
                temp = product[j];
                product[j] = product[j + 1];
                product[j + 1] = temp;
            }
        }
    }
}

/**
 * This function is design for to store product data into binary file
 */
void saveProductDetails(productData products[], int count)
{
    FILE *file = fopen("Product_data.bin", "wb");
    if (file == NULL)
    {
        printf(RED "Error opening file.\n" RESET);
        return;
    }

    for (int i = 0; i < count; i++)
    {
        int nameLen = strlen(products[i].productName) + 1; // +1 for null terminator

        fwrite(&products[i].productId, sizeof(int), 1, file);
        fwrite(&products[i].productQuantity, sizeof(int), 1, file);
        fwrite(&products[i].productPrice, sizeof(float), 1, file);
        fwrite(&nameLen, sizeof(int), 1, file);
        fwrite(products[i].productName, sizeof(char), nameLen, file);
    }
   // if(file)
    fclose(file);
}

/**
 * read product data from .bin file
 */
void loadProductData(productData products[], int *count)
{
    FILE *file = fopen("Product_data.bin", "rb");
    if (file == NULL)
    {
        printf(RED "Product_data file not Found. Starting fresh.\n" RESET);
        return;
    }

    int i = 0;
    while (i < MAX && fread(&products[i].productId, sizeof(int), 1, file) == 1)
    {
        fread(&products[i].productQuantity, sizeof(int), 1, file);
        fread(&products[i].productPrice, sizeof(float), 1, file);

        int nameLen;
        fread(&nameLen, sizeof(int), 1, file);
        products[i].productName = (char *)malloc(nameLen * sizeof(char));
        fread(products[i].productName, sizeof(char), nameLen, file);

        i++;
    }

    *count = i;
    fclose(file);
}

/**
 * write data into text file
 */
void storeProductDataToFile(productData product[], int position)
{
    FILE *file = fopen("product_data_text.txt", "w");
    if (file == NULL)
    {
        printf(RED "Error opening file for writing.\n" RESET);
        return;
    }

    for (int i = 0; i < position; i++)
    {
        fprintf(file, "%d,%s,%d,%.2f\n", product[i].productId, product[i].productName,
                product[i].productQuantity, product[i].productPrice);
    }

    fclose(file);
    printf(GREEN "Data successfully stored to file.\n" RESET);
}

/**
 *  read data from product text file
 */
void loadProductDataFromText(productData product[], int *position)
{
    FILE *file = fopen("product_data_text.txt", "r");
    if (file == NULL)
    {
        printf(RED "Error opening file for reading.\n" RESET);
        return;
    }

    char line[256];
    *position = 0;

    while (fgets(line, sizeof(line), file))
    {
        product[*position].productName = (char *)malloc(256);
        if (product[*position].productName == NULL)
        {
            printf(RED "Memory allocation failed!\n" RESET);
            exit(1);
        }

        sscanf(line, "%d,%[^,],%d,%f", &product[*position].productId, product[*position].productName,
               &product[*position].productQuantity, &product[*position].productPrice);
        (*position)++;
    }

    fclose(file);
    printf(GREEN "Data successfully retrieved from file.\n" RESET);
}

/**
 * store data into Customer_data_textCustomer_data_text text file
 */
void saveCustomerDataToText(customerinfo customer[], int count)
{
    FILE *file = fopen("Customer_data_text.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d\n", customer[i].customerId);
        fprintf(file, "%s\n", customer[i].name);
        fprintf(file, "%ld\n", customer[i].contactNumber);
        fprintf(file, "%s\n", customer[i].emailId);
    }

    fclose(file);
    printf(GREEN "Customer data successfully stored to text file.\n" RESET);
}

/**
 * read data into Customer_data_textCustomer_data_text text file
 */
void loadCustomerDataFromText(customerinfo customer[], int *count)
{
    FILE *file = fopen("Customer_data_text.txt", "r");
    if (file == NULL)
    {
        printf(RED "Customer_data not existing, starting fresh.\n" RESET);
        return;
    }

    int i = 0;
    while (i < MAX && fscanf(file, "%d\n", &customer[i].customerId) == 1)
    {
        char buffer[256];

        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = '\0';
        customer[i].name = strdup(buffer);

        fscanf(file, "%ld\n", &customer[i].contactNumber);

        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = '\0';
        customer[i].emailId = strdup(buffer);

        i++;
    }

    *count = i;
    fclose(file);
}

/**********************************************************************************
 * summary: these are Functions design for specific task which mostly have three
 *          strctures, this function mostly have two arguments which is strcture
 *          and updated position of array
 *
 *          structures are globaly declare that's why here taking void because
 *          we can't return array address directly
 *
 **********************************************************************************
 */