/***************************************************************************************************************
 * This is main File (main.c)
 *
 *
 *============================================================================
 * @file      main_text.c
 * @author    Rahul Shridhar Bansod
 * @brief     manage and executes other functions
 * @version   0.1v
 * @date      2024-06-06
 * @copyright Copyright (c)  public
 *
 *=============================================================================
 *
 *
 * Summary: In this project there have three main thing customer,product and billing
 *          project is design for add customer data into structure array like Id,name,
 *          email and contact number.
 *          This data store position by position while increament that position and this data
 *          also store in Text file and Binary file.
 *
 *          When initially run the code on that time text or binary file data store in structure
 *          variables
 *
 *          Some variables are statically allocate and some variables like name, email ...etc. are
 *          Dynamically allocate using calloc and realloc predefine functions
 *
 *          So what data already store in file that data get into structure
 *
 *          This thing also applicable for storing Product and Billing informations
 *
 *          There have different options for store data in structure, save into file, delete from data,
 *          sort data in assending order.
 *
 *          There have option to buy a product and put Customer Id for register bill on them for purchase
 *          and select product to buy, Qunatity, and based on Quantity price will be store in billing data
 *
 *          Also Quantity will be updated after buying product in database after that it will shows generated
 *          bill and store that bill into text file permanently.
 *
 *******************************************************************************************************************
 */

#include "header.h"      //include predefine libraries
#include "macros.h"      //include some useful macros
#include "structure.h"   //include all required strcture
#include "declaration.h" //include all declaration of function defination
#include "colors.h"      //to give color code to Strings

int count = 0;
int position = 0;
customerinfo customer[MAX];
productData Products[MAX];
customerBill bill[MAX];

/********************************************************
 * This is main function which Executes other functions
 * This is Menu
 ********************************************************
 */
int main()
{
    int choice = 0;
    char option;
    loadCustomerDataFromText(customer, &count);   // read data from file
    loadProductDataFromText(Products, &position); // read product data from file
    STAR_LINE(11)                                 // display start(*) line
    NEW_LINE                                      // macro for printf("\n");

        printf(BLUE "MINI PROJECT: CUSTOMER PRODUCT BILLING SYSTEM\n" RESET);
    printf(BBLACK "Current Time: %s" RESET, currentTime());
    NEW_LINE
    STAR_LINE(11)
    NEW_LINE
    while (1)
    {
        printf(MAGENTA " 1.add Customer information\n 2.Edit Customer Data\n 3.Delete Customer Data\n 4.display Customer information\n" RESET);
        printf(BLUE " 5.add product information\n 6.Edit product data\n 7.Delete Product Data\n 8.display product data\n" RESET);
        printf(GREEN " 9.buy products\n" RESET);
        printf(RED " 11.EXIT\n" RESET);

        printf(BBLACK YELLOW " Enter the choice:" RESET);
        __fpurge(stdin);
        scanf("%d", &choice);
        NEW_LINE
        switch (choice)
        {
        case 1: // add new Customer data
            addCustomerData(customer, count);
            count++;
            saveCustomerDataToText(customer, count);
            break;

        case 2: // edit customer data
            editCustomerData(customer, count);
            saveCustomerDataToText(customer, count);
            break;

        case 3: // delete customer data
            deleteCustomerData(customer, &count);
            saveCustomerDataToText(customer, count);
            break;

        case 4: // dispay Customer data
            displayCustomerData(customer, count);
            break;

        case 5: // add new product list
            addProductDetails(Products, position);
            position++;
            sortProductData(Products, position);
            // saveProductDetails(Products, position);
            storeProductDataToFile(Products, position);
            break;

        case 6: // Edit product data
            editProductDetails(Products, position);
            sortProductData(Products, position);
            // saveProductDetails(Products, position);
            storeProductDataToFile(Products, position);
            break;

        case 7: // Delete product Data
            deleteProductDetails(Products, &position);
            sortProductData(Products, position);
            // saveProductDetails(Products, position);
            storeProductDataToFile(Products, position);
            break;

        case 8: // display product data
            sortProductData(Products, position);
            displayProducts(Products, position);
            break;

        case 9: // buy produts
            addBillDataText(bill, position);
           displayBill(bill, position);
            break;
        case 11: // Exiting from program
            printf(RED "EXITING...\n" RESET);
            exit(1);
        default:
            printf(RED "enter the valid choice\n" RESET);
        }
    }
}

/**
 *
 * TEST CASES:
 * 1) when add new customer details and if id is already present then its shows warning:
 *                                 Customer with This Id is already present !
 *                                 Please add with Different Id
 *
 * 2) when user enter Id as a Zero(0): Do not Enter ZERO as an Id
 *
 * 3) When user buy a product after that file update the data decrease quantities after buying
 *
 * 4) Enter Customer Id for billing:(0 for Main Menu) : goto Main Menu
 *
 * 5) Enter the Product Id: (any Present Id) -> Product Id id already Exist
 *                           please enter new Id
 *                           Press 0 for Exit
 *
 */