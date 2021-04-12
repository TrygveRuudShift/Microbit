#include "uart.h"
#include "gpio.h"

void uart_init() {
    GPIO->DIRSET = (1 << PORT_TGT_TXD); // skal det heller være GPIO->PIN_CNF[24] = 1; og [25] = 0? Så på github ;)
    GPIO->DIRCLR = (1 << PORT_TGT_RXD);

    UART->PSELTXD = PORT_TGT_TXD;
    UART->PSELRXD = PORT_TGT_RXD;

    UART->BAUDRATE = 0x00275000; // BAUD9600, actual rate 9598

    UART->PSELRTS = 0xFFFFFFFF; // Disconnect
    UART->PSELCTS = 0xFFFFFFFF;

    UART->ENABLE = 4; // Enable UART
    UART->STARTRX = 1;
}

void uart_send(char letter) {
    UART->STARTTX = 1;
    UART->TXD = letter;
    while (!UART->TXDRDY);
    
    UART->TXDRDY = 0; // Trengs dette?
    // UART->STOPTX = 1;
}

char uart_read() {
    UART->STARTRX = 1;

    if (UART->RXDRDY) {
        UART->RXDRDY = 0;
        return UART->RXD;
    } else {
        return '\0';
    }
}