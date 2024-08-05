/******************************************************************
 *                 * structure.h *
 *
 * In this file have strctures of products, customers, bill data
 *
 ******************************************************************
 */

#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct Products
{
    int productId;
    char *productName;
    int productQuantity;
    float productPrice;
} productData;

typedef struct Customer
{
    int customerId;
    char *name;
    long int contactNumber;
    char *emailId;
} customerinfo;

typedef struct Customer_bill
{
    int billNumber;
    char *customerName;
    struct Customer ConsumerData;
    struct Products products[MAX]; // add struct Products structure array here
    float totalBill;
} customerBill;

#endif

/******************************************************************************************
 * Summary: In this file have declared strctures about products details, customer details,
 *          billing details.
 *
 *          This details are use for store all information and also this is read and write
 *          in a file.
 *******************************************************************************************
 */