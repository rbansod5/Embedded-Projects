/***********************************
 * Customer related declarations   *
 ***********************************
 */
void addCustomerData(customerinfo customer[], int position);
void saveCustomerData(customerinfo customer[], int);
void displayCustomerData(customerinfo customer[], int position);
void loadCustomerData(customerinfo customer[], int *count);
void deleteCustomerData(customerinfo customer[], int *position);
void editCustomerData(customerinfo customer[], int position);
void saveCustomerDataToText(customerinfo customer[], int count);
void loadCustomerDataFromText(customerinfo customer[], int *count);

/***********************************
 * Product related declarations    *
 ***********************************
 */
void displayProducts(productData products[], int numProducts);
void addProductDetails(productData product[], int position);
void saveProductDetails(productData products[], int count);
void loadProductData(productData products[], int *count);
void editProductDetails(productData product[], int position);
void deleteProductDetails(productData product[], int *position);
void sortProductData(productData product[], int position);
void storeProductDataToFile(productData product[], int position);
void loadProductDataFromText(productData product[], int *position);

/***********************************
 * Billing related declarations    *
 ***********************************
 */
void addBillingData(customerBill bill[], int position);
void saveBillingData(customerBill bill[], int position);
void addBillData(customerBill bill[], int position);
void displayBill(customerBill bill[], int position);
void addBillDataText(customerBill bill[], int billPosition);

/******************************
 * other related declarations *
 ******************************
 */
char *getString(char *string);
char *currentTime();