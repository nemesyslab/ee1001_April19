/*
 * File:   main.c
 * Author: mustafa
 *
 * Created on 15 Nisan 2014 Sal?, 02:33
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 8000000
#define CLOCK_FREQ  8000000

/*
 *
 */
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// Function Prototypes
void turnOnLed(int, int);

int main() {
  int dataReg;
  int bitCount=0;
  int timeCnt=0;
  int dataReg2;
  int light;
  int prevEnter, enter, posedge;

  TRISA = 0;           // set direction to be output
  TRISB = 0x40;           // set direction to be output
  TRISC = 0;           // set direction to be output
  TRISD = 0;           // set direction to be output
  TRISE = 0x01;           // set direction to be output
  PORTA = 0x00;
  PORTB = 0x00;
  PORTC = 0x00;
  PORTD = 0x00;
  ADCON1 = 0x02;

  while(1){
      __delay_ms(100); // wait 100 ms
      prevEnter = enter;
      enter = PORTBbits.RB6;
      posedge = enter & !prevEnter;
      if(posedge){
          dataReg2 = (dataReg2<<1) | PORTEbits.RE0;
          bitCount++;
          if(bitCount == 6){
            turnOnLed(dataReg, 0);
            dataReg = dataReg2;
            dataReg2 = 0;
            light = 1;
            timeCnt = 0;
            bitCount = 0;
          }
      }
      turnOnLed(dataReg, light);
      if(timeCnt == 10){
          timeCnt = 0;
          light = !light;
      }
      timeCnt++;
  }
  // Endless loop

    return (EXIT_SUCCESS);
}

void turnOnLed(int _dataReg, int _light){
    int portNo, dataBit;

    portNo = _dataReg>>3;
    dataBit = _light << (_dataReg & 7);
    switch(portNo){
        case 1: PORTA = dataBit; break;
        case 2: PORTB = dataBit; break;
        case 3: PORTC = dataBit; break;
        case 4: PORTD = dataBit; break;
    }
}


