/*************************************
 * This is main File (main.c)
 *************************************
 */


#include "header.h"
#include "macros.h"
#include "structure.h"
#include "declaration.h"
#include "colors.h"

int count = 0;
int position = 0;
customerinfo customer[MAX];
productData Products[MAX];
customerBill bill[MAX];

 
 /*
 * This is main function which Executes other functions
 * This is Menu
 */
int main()
{
    int choice = 0;
    loadCustomerData(customer, &count); // read data from file
    //loadCustomerDataFromText(customer, &count);
     loadProductData(Products, &position); // read product data from file
    //retrieveProductDataFromFile(Products, &position);
    STAR_LINE(2 * position)
    NEW_LINE
    printf(BLUE "MINI PROJECT: CUSTOMER PRODUCT BILLING SYSTEM" RESET);
    NEW_LINE
    STAR_LINE(2 * position)
    NEW_LINE
    while (1)
    {
        printf(MAGENTA " 1.add Customer information\n 2.Edit Customer Data\n 3.Delete Customer Data\n 4.display Customer information\n" RESET);
        printf(BLUE " 5.add product information\n 6.Edit product data\n 7.Delete Product Data\n 8.display product data\n 9.buy products\n 10.product billing\n" RESET);
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
            //saveCustomerDataToText(customer, count);
            saveCustomerData(customer, count);
            break;

        case 2: // edit customer data
            editCustomerData(customer, count);
            //saveCustomerDataToText(customer, count);
            saveCustomerData(customer, count);
            break;
        case 3: // delete customer data
            deleteCustomerData(customer, &count);
            //saveCustomerDataToText(customer, count);
            saveCustomerData(customer, count);
            break;
        case 4: // dispay Customer data
            displayCustomerData(customer, count);
            break;
        case 5: // add new product list
            addProductDetails(Products, position);
            position++;
            sortProductData(Products, position);
            saveProductDetails(Products, position);
            //storeProductDataToFile(Products, position);
            break;
        case 6: // Edit product data
            editProductDetails(Products, position);
            sortProductData(Products, position);
            saveProductDetails(Products, position);
            //storeProductDataToFile(Products, position);
            break;
        case 7: // Delete product Data
            deleteProductDetails(Products, &position);
            sortProductData(Products, position);
            saveProductDetails(Products, position);
           //storeProductDataToFile(Products, position);
            break;
        case 8: // display product data
            sortProductData(Products, position);
            displayProducts(Products, position);
            break;
        case 9: // buy produts
            addBillData(bill, position);
            break;
        case 10: // billing
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
 * summary:
 *
 *
 * TEST CASES:
 * 1) when add new customer details and if id is already present then its shows warning:
 *                                 Customer with This Id is already present !
 *                                 Please add with Different Id
 *
 * 2) when i enter Id as a Zero(0): Do not Enter ZERO as an Id
 *
 * 3) 
 *
 */