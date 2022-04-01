/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16F1508
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

#define Device_Address 0x40 

unsigned short mask(unsigned short temp) {
  switch (temp) {
    case 0 : return 0x3F;
    case 1 : return 0x06;
    case 2 : return 0x5B;
    case 3 : return 0x4F;
    case 4 : return 0x66;
    case 5 : return 0x6D;
    case 6 : return 0x7D;
    case 7 : return 0x07;
    case 8 : return 0x7F;
    case 9 : return 0x6F;
  } //case end
}

unsigned short i, k, disp, num = 0;

/*
  Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
//    Init_MCP23008(0x40);
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
     

      
    while (1)
    {     
        __delay_us(1);
     // Read INTCAP
//      I2C_Start(); // Issue start signal
//      I2C_Write(0x40); // Address + Write bit
//      I2C_Write(0x08);   // Address of INTCAP register
//      //Soft_I2C_Stop();
//      I2C_Start(); // Issue start signal
//      I2C_Write(0x40+1); // Address + Read bit
//      __delay_ms(300);
//      k = I2C_Read(0); // Read byte and don't acknowlegde
//      I2C_Stop();
//      disp = mask(num);
//      I2C_Start(); // Issue start signal
//      I2C_Write(0x40); // Address + Write bit
//      I2C_Write(0x09); // Select GPIO register
//      I2C_Write(disp); // Send Num
//      I2C_Stop();
//      num = num + 1;
//      if(num == 10) num=0;
    MCP23008_Output(0x0F);  // Set MCP23008 output as 0x0F 
        __delay_ms(250); 
    MCP23008_Output(0xF0);  // Set MCP23008 output as 0x0F 
        __delay_ms(250); 
        
    }
}



/**
 End of File
*/