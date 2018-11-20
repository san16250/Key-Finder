/*
 * File:   receptor.c
 * Author: Christian
 *
 * Created on October 11, 2018, 1:40 AM
 */


// PIC16F688 Configuration Bit Settings

// 'C' source line config statements

// CONFIG

#define _XTAL_FREQ 8000000
#define buz PORTCbits.RC1
#include <xc.h>

#include <htc.h>
#include <stdio.h>


#pragma config FOSC = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Detect (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

void init(void)
{
    //init PORTS
    PORTA = 0;
    PORTC = 0;
    TRISA = 0b000000;        //    all outputs
    TRISC = 0b100000;        //    all outputs, except RX on RC7
    ANSEL = 0;                //  disable all analog inputs

    
    //init USART
    BAUDCTL = 0b00000000;    //    SCKP=0, BRG16=0, WUE=0, ABDEN=0
    TXSTA = 0b00100100;        //    8-bit, tx-enb, asynch, BRGH=1
    SPBRG = 51;                //    9600 baud with 8MHz clock. Table 12-5 in datasheet
    RCSTA = 0b10010000;        //    SPEN=1, CREN=1, addr-det disabled.

}

char UART_RxChar()
{
    while(RCIF==0);    // Wait till the data is received 
    //RCIF=0;            // Clear receiver flag
    return(RCREG);     // Return the received data to calling function
}
 
/*unsigned char UART_RxChar()
{
    if(PIR1bits.RCIF==1){//si el bit5 del registro PIR1 se ha puesto a 1
    return RCREG;//devuelve el dato almacenado en el registro RCREG
    }
    else//sino
        return;//retorna sin hacer nada
}*/

void main(void) 
{
    OSCCON = 0b01110000;    //    set internal clock to 8MHz
    init();
    char x = 'A';
    int i;
    
    char ch;
    
    
    
    

        while (1) {
                ch = UART_RxChar();    
        
 

        
        while (ch == 'A'){
            PORTCbits.RC2 = 1;
            PORTCbits.RC1 = 1;
            //PORTCbits.RC0 = 1;
            ch = UART_RxChar();  
            
        }
        while (ch == 'B'){
            PORTCbits.RC2 = 0;
            PORTCbits.RC1 = 0;
            //PORTCbits.RC0 = 0;
            ch = UART_RxChar();  
        }    
           
        
        return;
        }
        }
        
        
    
    
    
