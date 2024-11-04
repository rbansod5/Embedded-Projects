// Structure to hold price information
typedef struct
{
    double lastPrice;            // The most recent trading price of the stock
    double change;               // Change in price from the previous trading session
    double pChange;              // Percentage change in price from the previous trading session
    double previousClose;        // Closing price from the previous trading session
    double open;                 // Opening price of the stock for the current trading session
    double close;                // Closing price of the stock for the current trading session
    double vwap;                 // Volume-weighted average price for the stock
    double lowerCP;              // Lower circuit price limit for the stock
    double upperCP;              // Upper circuit price limit for the stock
    double basePrice;            // Base price for the stock, usually used for calculations related to derivatives
    struct
    {
        double min;              // Minimum price during the intraday trading session
        double max;              // Maximum price during the intraday trading session
        double value;            // Current price during the intraday session
    } intraDayHighLow;           // Nested structure to hold intra-day high and low values
    struct
    {
        double min;              // Minimum price for the week
        double max;              // Maximum price for the week
        const char *minDate;     // Date of the minimum price for the week
        const char *maxDate;     // Date of the maximum price for the week
        double value;            // Current price for the week
    } weekHighLow;               // Nested structure to hold weekly high and low values
} PriceInfo;

// Structure to hold industry information
typedef struct
{
    const char *macro;          // Macroeconomic category (e.g., Energy, Technology)
    const char *sector;         // Specific sector in which the stock operates (e.g., Oil & Gas)
    const char *industry;       // Industry category (e.g., Oil Exploration)
    const char *basicIndustry;  // Basic industry category, possibly a broader classification
} IndustryInfo;

// Structure to hold security information
typedef struct
{
    const char *boardStatus;    // Status of the stock on the exchange (e.g., Main, SME)
    const char *tradingStatus;   // Current trading status (e.g., Active, Suspended)
    const char *tradingSegment;  // Segment of trading (e.g., Normal Market, Derivatives)
    bool slb;                    // Indicates if the stock is eligible for stock lending and borrowing
    const char *classOfShare;    // Class of share (e.g., Equity, Preference)
    bool derivatives;            // Indicates if derivatives are available for the stock
    double faceValue;            // Face value of the stock
    long issuedSize;             // Total number of shares issued
} SecurityInfo;

// Structure to hold metadata
typedef struct
{
    const char *series;          // Trading series (e.g., EQ, T0)
    const char *symbol;          // Stock symbol or ticker
    const char *isin;            // International Securities Identification Number
    const char *status;          // Listing status of the stock (e.g., Listed, Delisted)
    const char *listingDate;     // Date when the stock was listed
    const char *industry;        // Industry classification
    const char *lastUpdateTime;  // Last time the stock data was updated
    double pdSectorPe;           // Price-to-earnings ratio for the sector
    double pdSymbolPe;           // Price-to-earnings ratio for the stock itself
    const char *pdSectorInd;     // Sector index (e.g., NIFTY 50)
    const char *pdSectorIndAll[20]; // Array holding all sector indices the stock belongs to (size may need adjustment)
} Metadata;

// Structure to hold pre-open market data
typedef struct
{
    struct
    {
        double price;            // Pre-open price for the stock
        long buyQty;             // Quantity available for buying at pre-open price
        long sellQty;            // Quantity available for selling at pre-open price
    } preopen[10];               // Array holding pre-open data for multiple price levels (size may need adjustment)
    struct
    {
        long buy;                // Total buy quantity in the at-the-open order book
        long sell;               // Total sell quantity in the at-the-open order book
    } ato;                        // At-the-open (ATO) order book statistics
    double IEP;                  // Indicative Equilibrium Price
    long totalTradedVolume;      // Total volume of shares traded during the session
    double finalPrice;           // Final price of the stock at the end of trading session
    long finalQuantity;          // Final quantity of shares traded
    const char *lastUpdateTime;  // Last time the pre-open market data was updated
    long totalBuyQuantity;       // Total quantity of buy orders in the order book
    long totalSellQuantity;      // Total quantity of sell orders in the order book
    long atoBuyQty;              // Quantity of buy orders at the open
    long atoSellQty;             // Quantity of sell orders at the open
    double change;               // Change in price at pre-open
    double perChange;            // Percentage change at pre-open
    double prevClose;            // Previous closing price
} PreOpenMarket;

// Structure to hold the main stock data
typedef struct
{
    struct
    {
        char symbol[10];          // Stock symbol (e.g., ONGC)
        char companyName[100];    // Full company name
        char industry[50];        // Industry of the company
        char activeSeries[5][10]; // Array holding active series the stock is listed on
        bool isFNOSec;            // Indicates if it is a Futures and Options (F&O) security
        bool isCASec;             // Indicates if it is a Capital Account security
        bool isSLBSec;            // Indicates if it is a Securities Lending and Borrowing security
        bool isDebtSec;           // Indicates if it is a Debt security
        bool isSuspended;         // Indicates if trading is suspended for the stock
        char isin[20];            // International Securities Identification Number
        char slb_isin[20];        // ISIN for securities lending and borrowing
    } info;                      // Basic info about the stock
    Metadata metadata;           // Metadata related to the stock
    SecurityInfo securityInfo;   // Security information of the stock
    PriceInfo priceInfo;         // Price-related information
    IndustryInfo industryInfo;   // Industry-related information
    PreOpenMarket preOpenMarket; // Pre-open market data for the stock
} StockData;

// Define the linked list node
typedef struct StockNode
{
    StockData stock;              // Stock data contained within the node
    struct StockNode *next;       // Pointer to the next node in the linked list
} StockNode;
