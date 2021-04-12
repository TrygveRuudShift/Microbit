#ifndef UART
#define UART

#define PORT_TGT_RXD 25
#define PORT_TGT_TXD 24

#define UART ((NRF_UART_REG*)0x40002000)


void uart_init();
void uart_send(char letter);
char uart_read();

typedef struct
{
    volatile uint32_t STARTRX;
    volatile uint32_t STOPRX;
    volatile uint32_t STARTTX;
    volatile uint32_t STOPTX;

    volatile uint32_t RESERVED0[0x3];

    volatile uint32_t SUSPEND;

    volatile uint32_t RESERVED1[0x38];

    // Events
    volatile uint32_t CTS;
    volatile uint32_t NCTS;
    volatile uint32_t RXDRDY;

    volatile uint32_t RESERVED2[0x4];

    volatile uint32_t TXDRDY;

    volatile uint32_t RESERVED3[0x1];

    volatile uint32_t ERROR;

    volatile uint32_t RESERVED4[0x7];

    volatile uint32_t RXTO;

    volatile uint32_t RESERVED5[0x6E];

    
    // Registrers
    volatile uint32_t INTEN;
    volatile uint32_t INTENSET;
    volatile uint32_t INTENCLR;

    volatile uint32_t RESERVED6[0x59];

    volatile uint32_t ERRORSRC;

    volatile uint32_t RESERVED7[0x1F];

    volatile uint32_t ENABLE;

    volatile uint32_t RESERVED8[0x1];

    volatile uint32_t PSELRTS;
    volatile uint32_t PSELTXD;
    volatile uint32_t PSELCTS;
    volatile uint32_t PSELRXD;
    volatile uint32_t RXD;
    volatile uint32_t TXD;

    volatile uint32_t RESERVED9[0x1];

    volatile uint32_t BAUDRATE;
    
    volatile uint32_t RESERVED10[0x11];

    volatile uint32_t CONFIG;
} NRF_UART_REG;


#endif
