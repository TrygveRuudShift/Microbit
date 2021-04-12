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

}

char uart_read() {

}