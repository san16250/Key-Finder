/*
 * File:   keyfinder.c
 * Author: Christian
 *
 * Created on October 9, 2018, 9:04 PM
 */


#define _XTAL_FREQ 8000000

#include <xc.h>
#include "flex_lcd.h"
#include <htc.h>
#include <stdio.h>    //printf, puts, putchar
 // _XTAL_FREQ must be defined for the __delay_ms() macro to work correctly




 //CONFIG1 for PIC16F887
__CONFIG(LVP_OFF & FCMEN_OFF & IESO_OFF & BOREN_ON & CPD_OFF & CP_OFF & MCLRE_OFF & PWRTE_ON & WDTE_OFF & FOSC_INTRC_NOCLKOUT);
 //CONFIG2 for PIC16F887
__CONFIG(WRT_OFF & BOR4V_BOR40V);







    


 //-----------------------------------------------------------------------------
//all initialisation, performed once.

void init(void)
{
    //init PORTS
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    TRISA = 0b00000000;        //    all outputs
    TRISB = 0b00000010;        //    all outputs excepto por RB1
    TRISC = 0b10000000;        //    all outputs, except RX on RC7
    ANSEL = 0;                //  disable all analog inputs
    ANSELH = 0;
    
    //init USART
    BAUDCTL = 0b00000000;    //    SCKP=0, BRG16=0, WUE=0, ABDEN=0
    TXSTA = 0b00100100;        //    8-bit, tx-enb, asynch, BRGH=1
    SPBRG = 51;                //    9600 baud with 8MHz clock. Table 12-5 in datasheet
    RCSTA = 0b10010000;        //    SPEN=1, CREN=1, addr-det disabled.
    Lcd_Init();     //inicializamos el lcd
    Lcd_Cmd(LCD_CLEAR);		//limpiamos lcd
    Lcd_Cmd(LCD_CURSOR_OFF);	//apagamos el cursor
    __delay_ms(100);		//esperamos 100ms
}


 
void main(void)
{
    OSCCON = 0b01110000;    //    set internal clock to 8MHz
    init();
    char x = 'A';
    char y = 'B';
    int i;
    unsigned char buffer1[20];
    
         
    while (PORTBbits.RB1 == 0){
        Lcd_Out(1, 4, "Presiona");
        Lcd_Out(2, 4, "Boton");
        TXREG = y;
            }
        


    



    
    
    while(PORTBbits.RB1 == 1){
        PORTBbits.RB0 = 1;
        Lcd_Out(1, 4, "Buscando");
        Lcd_Out(2,4, "Llaves");
        TXREG = x;
        __delay_ms(5);
    }
    return;
     while (1);    //loop forever
}