#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// (x, y) values for the location of the store
const double SHOP_LOCATION_X = 4.5;
const double SHOP_LOCATION_Y = 3.8;
// the name of the file that contains all the products
const char FILE_NAME[] = "products.txt";
// SKUs of products that have 15% discount
const int DISCOUNTED[7] = {27638, 72646, 39044, 50948, 52363, 37462, 38511};


int mainMenu();
double findNearestShop();
void listProductsCheaperThan(double price);
int addProduct(int sku, double price);
void processPurchase(int numOfItems, int itemSkus[]);
void drawPrices(int numOfProducts, int productSkus[]);

/* Helper functions */
double manhattanDistance(double x1, double y1, double x2, double y2);
double euclideanDistance(double x1, double y1, double x2, double y2);
int isOnDiscount(int sku);
double discountedPrice(double price);
double getPriceBySku(int sku);
int doublesAreEqual(double x, double y);


int main()
{
    int shouldExit;
    do
    {
        shouldExit = mainMenu();
    } while (shouldExit != 1);
    printf("Thanks for using this program!\n");
    return 0;
}


int mainMenu()
{
    // printing the menu text
    printf("Welcome! Please choose one of the following options:\n");
    printf("1. Find Nearest Shop.\n");
    printf("2. List products cheaper than a price.\n");
    printf("3. Add a new product to the store.\n");
    printf("4. Process a Purchase.\n");
    printf("5. Draw a figure of the prices.\n");
    printf("6. Exit.\n>> ");

    // assigning variables
    int menuChoice, numOfProducts, productSkus[numOfProducts];
    int sku;
    double price;
    scanf("%d", &menuChoice);

    // using switch statement for menu choice
    switch (menuChoice)
    {
    case 1:
        findNearestShop();
        break;

    case 2:
        printf("Enter the price: \n");
        scanf("%lf", &price);
        listProductsCheaperThan(price);
        break;

    case 3:
        printf("Please enter sku and price of item :\n");
        scanf("%d %lf", &sku, &price);
        addProduct(sku, price);
        break;

    case 4:

        break;

    case 5:
        
        break;

    case 6:

        break;

    default:
        printf("Invalid Choice\n");
        return 0;
    }
    return 1;
}


double findNearestShop()
{
    // assigning variables
    int numOfShops;
    double pointX, pointY;
    char measureChoice[13];

    printf("Enter the distance measure you would like to use:\n");
    printf("Type euclidean for Euclidean distance.\nOr type manhattan for Manhattan distance.\n");
    scanf("%s", measureChoice);
    if (strcmp(measureChoice, "manhattan") == 0)
    {
        manhattanDistance(SHOP_LOCATION_X, SHOP_LOCATION_Y, pointX, pointY);
    }
    else if (strcmp(measureChoice, "euclidean") == 0)
    {
        euclideanDistance(SHOP_LOCATION_X, SHOP_LOCATION_Y, pointX, pointY);
    }
    else
    {

        while (measureChoice != "manhattan" || measureChoice != "euclidean")
        {
            printf("Invalid Input. Please re-enter your choice of distance measure: \n");
            scanf("%s", measureChoice);
            if (strcmp(measureChoice, "manhattan") == 0)
            {
                manhattanDistance(SHOP_LOCATION_X, SHOP_LOCATION_Y, pointX, pointY);
                break;
            }
            else if (strcmp(measureChoice, "euclidean") == 0)
            {
                euclideanDistance(SHOP_LOCATION_X, SHOP_LOCATION_Y, pointX, pointY);
                break;
            }
        }
    }

    return 0.0;
}


void listProductsCheaperThan(double price)
{
    // read the first line of products.txt and assign the value to int n
    int n;
    FILE *fp = fopen("products.txt", "r");
    if(fp == NULL)
    {
        printf("no file found\n");
    }
    fscanf(fp, "%d", &n);
    // loop over the n line and take two values int sku and double price
    int sku;
    double price1;
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d %lf", &sku, &price1);
        if (isOnDiscount(sku))
        {
            price1 = discountedPrice(price1);
        }
        if (price1 < price)
        {
            printf("Product %d has a price of %.2lf\n", sku, price1);
        }
    }
    fclose(fp);
}

/*
    Adds the product to the list of products in the file IF the SKU is unique.
    It also updates the number of products at the top of the file.

    If the product is added succesfully, RETURNS 1, otherwise RETURNS 0
*/
int addProduct(int sku, double price)
{
    FILE *in;
    FILE *out;
    in=fopen("products.txt","r");
    if(in==NULL)
    printf("no file found\n");
    int numOfProducts;
    fscanf(in, "%d", &numOfProducts);
    int everySku[numOfProducts];
    double everyPrice[numOfProducts];
    for(int i=0 ; i < numOfProducts ; i++){
        fscanf(in, "%d %lf", &everySku[i], &everyPrice[i]);
        if(everySku[i]==sku){
        fclose(in);
        printf("Error! Product is already in the list!\n");
        return 0;
        }
        

    }
    
    fclose(in);
    numOfProducts += 1;
    printf("%d", numOfProducts);
    out==fopen("products.txt","w");
    if(out==NULL)
    printf("no file found\n");
    fprintf(out,"%d\n", numOfProducts);
    for(int i=0 ; i < numOfProducts ; ++i){
    fprintf(out, "%d %lf\n", everySku[i], everyPrice[i]);
    }
    fprintf(out, "%d %lf", sku, price);
    fclose(out);
    printf("Product added successfully!");
    return 1;

}

/*
    Accepts the number of items the customer is buying, and an array of SKUs
    of those items the customer is buying.
    It prints all the purchase details on the screen, and writes them into a file
    called "receipt.txt" along with the total cost of the whole purchase.
    Takes into account the discounted products in the DISCOUNTED constant array.
    If any provided SKU is not in the list of products, PRINT an error message as follows and continue:
        "SKU 58312 is not available! Ignoring!"

    E.g., the file "receipt.txt" will look like this after this function ends:

    Customer purchased 3 items:
    - 45763 2 5.00
    - 31402 3 3.60
    - 68178 1 19.50
    ===============
    Total: 28.10

*/
void processPurchase(int numOfItems, int itemSkus[])
{
    return;
}

/*
    Draws a picture that shows the prices of the passed product SKUs.
    Each product will be represented by a black bar that has width 30, and
    the length of the bar will be equal to ceil(price of product) x 10.
    Separate bars from each other by 20 white pixels.

    The picture should be 500 pixels of height, and 30 x numOfProducts + 20 x numOfProducts + 1

    If any provided SKU is not in the list of products, PRINT an error message as follows and continue:
        "SKU 58312 is not available! Ignoring!"
*/
void drawPrices(int numOfProducts, int productSkus[])
{
    int width;
    printf("Enter number of products you wish to compare :\n");
    scanf("%d", &numOfProducts);
    width = 30 * numOfProducts + 20 * (numOfProducts + 1);
    int image[500][width];
    //int productSkus[numOfProducts];
    //for
    return;
}

/*
    RETURNS the Manhattan Distance between 2 points (x1, y1) and (x2, y2)
*/
double manhattanDistance(double x1, double y1, double x2, double y2)
{
    // assigning variables
    int numOfShops;
    double pointX, pointY, manDistance;

    // asking user for amount of shops nearby
    printf("Enter number of shops nearby:\n");
    scanf("%d", &numOfShops);

    // using a for loop to keep inserting shop distances
    for (int i = 0; i < numOfShops; ++i)
    {
        // asking user for x and y coordinates of shops
        printf("Enter X and Y coordinates of current shop:\n");
        scanf("%lf %lf", &pointX, &pointY);

        // calculating manhattan distance using fabs function
        manDistance = fabs(pointY - SHOP_LOCATION_Y) + fabs(pointX - SHOP_LOCATION_X);
        printf("The manhattan distance is %.2lf\n", manDistance);
    }
    return 0.0;
}

/*
    RETURNS the Euclidean Distance between 2 points (x1, y1) and (x2, y2)
*/
double euclideanDistance(double x1, double y1, double x2, double y2)
{
    // assigning variables
    int numOfShops;
    double storeX, storeY, eucDistance;

    // asking user for amount of shops nearby
    printf("Enter number of shops nearby:\n");
    scanf("%d", &numOfShops);

    // using a for loop to keep inserting shop distances
    for (int i = 0; i < numOfShops; ++i)
    {
        // asking user for x and y coordinates of shops
        printf("Enter X and Y coordinates of current shop:\n");
        scanf("%lf %lf", &storeX, &storeY);

        // calculating euclidean distance using square root and power functions
        eucDistance = sqrt(pow((SHOP_LOCATION_Y - storeY), 2) + pow((SHOP_LOCATION_X - storeX), 2));
        printf("The euclidean distance is %.2f \n", eucDistance);
    }
    return 0.0;
}

/*
    RETURNS 1 if the passed SKU is on discount, otherwise RETURNS 0
*/
int isOnDiscount(int sku)
{
    // using for loop to test if SKU inside discounted array
    for (int i = 0; i < 7; ++i)
    {
        if (sku == DISCOUNTED[i])
        {
            return 1;
        }
    }

    return 0;
}

/*
    RETURNS the price after a 15% sale.
*/
double discountedPrice(double price)
{
    return price * 0.85;
}

/*
    RETURNS the price of the given SKU, or -1 if the SKU does not exist in the list of products

    Takes into account the discounted products in the DISCOUNTED constant array.
*/
double getPriceBySku(int sku)
{
    
}

/*
    You do not need to implement this function, it is already implemented for you.

    Use this function when you want to compare 2 double values for equality.
    Doubles can have precision problems, so doing x == y sometimes gives the
    wrong answer. This functions considers the minor errors that may happen when
    comparing doubles.

    Example of usage:,l.

    if (doublesAreEqual(num1, num2) == 1) {
        // do something
    }

    The function will RETURN 1 if the 2 variables are equal, otherwise it will
    RETURN 0.
*/
int doublesAreEqual(double x, double y)
{
    return fabs(x - y) < 1.0e-8;
}
