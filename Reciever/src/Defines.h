//frequency channel and rf95 instancing
#define RF95_FREQ 905.0

#define TIMEOUT 300
#define MAX_TIMEOUTS 3

#define BOARD BOARD_M0 // BOARD_32U4

//defines for all boards
#if BOARD == BOARD_M0 
    #define BLINKER 13
    #define RFM95_CS 8
    #define RFM95_RST 4
    #define RFM95_INT 3
#elif BOARD == BOARD_32U4 
    #define BLINKER 13
    #define RFM95_CS   8
    #define RFM95_RST  4
    #define RFM95_INT  7
#endif
