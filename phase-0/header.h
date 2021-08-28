//play back first track command 
#define START_BYTE 0x7E
#define VERSION    0xFF
#define LENGTH     0x06

#define FEEDBACK   0x00

#define END_BYTE   0xEF



// USART config 
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)
#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)


//take_query function 
enum{
    STARTING ,
    VERSION ,
    LENGTH ,
    QUERY ,
    FEEDBACK ,
    PARAM_MSB ,
    PARAM_LSB ,
    CHCK_MSB , 
    CHCK_LSB ,
    ENDING
}