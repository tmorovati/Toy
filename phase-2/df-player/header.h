#define BUTTON_PORTA
//#define DEBUG
/************Serial_Commands_Format***************/
#define START_BYTE       0x7E //first byte_start
#define VERSION_BYTE     0xFF //second byte_version
#define LENGTH_BYTE      0x06 //third byte_length
                            //fourth byte_cmd
#define FD_BYTE          0xFF //FIFth byte_feedback
#define NO_FD_BYTE       0x00 //FIFth byte_feedback
                              //parameter_msb
                              //parameter_lsb
                              //checksum_msb
                              //checksum_lsb
#define END_BYTE         0xEF //end_byte


//Returned data from modul
/********Query ******/
#define ONLINE_EQUIPMENT    0x3F //after modul is power_on
#define FINISH_PLAYING_SD   0x3D //after track is finished in SD_CARD
/********which_equipment******/
#define USB_ONLINE 0x0001
#define SD_ONLINE  0x0002
#define USB_SD     0x0003
#define PC         0x0004

/****************************/

//df_phase
enum
{
    STARTING,
    VERSION,
    LENGTH,
    QUERY,
    FD_BACK,
    PARAM_MSB,
    PARAM_LSB,
    CHECK_MSB,
    CHECK_LSB,
    ENDING
};

enum
{
    NOT_READY,
    READY
};
/******* BUTTON ******/
#ifdef BUTTON_PORTA
    #define BUTTON_DDR  DDRA
    #define BUTTON_PORT PORTA
    #define BUTTON_PIN  PINA
#else
#ifdef BUTTON_PORTB
    #define BUTTON_DDR  DDRB
    #define BUTTON_PORT PORTB
    #define BUTTON_PIN  PINB
#else
#ifdef BUTTON_PORTC
    #define BUTTON_DDR  DDRC
    #define BUTTON_PORT PORTC
    #define BUTTON_PIN  PINC
#else
#ifdef BUTTON_PORTD
    #define BUTTON_DDR  DDRD
    #define BUTTON_PORT PORTD
    #define BUTTON_PIN  PIND
#else

#endif
#endif
#endif
#endif

#define SHAME     (1<<0)
#define SADNESS   (1<<1)
#define SURPRISE  (1<<2)
#define ANGER     (1<<3)
#define HAPPINESS (1<<4)
#define FEAR      (1<<5)

enum
{
    key_0,
    key_1,
    key_2,
    key_3,
    key_4,
    key_5,
    NO_KEY
};
/*******UCSRA_Configurotion*********/
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)
#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)
/**********Buffer**********/
#define MAX_UART_BUFFER_SIZE    32

enum
{
    EMPTY ,
    FULL
};







