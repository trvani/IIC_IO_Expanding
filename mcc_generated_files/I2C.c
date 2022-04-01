#include <xc.h>
#include "I2C.h"
#include "mcc.h"


// Function Purpose: Configure I2C module
void InitI2C(void)
{	
	SDA_DIR = 1;		// Make SDA and 
	SCK_DIR = 1;		// SCK pins input

	SSPADD  = ((_XTAL_FREQ/4000)/I2C_SPEED) - 1;	
	SSPSTAT = 0x80;		// Slew Rate control is disabled
	SSPCON  = 0x28;		// Select and enable I2C in master mode
}


// Function Purpose: I2C_Start sends start bit sequence
void I2C_Start(void)
{
	SEN = 1;			// Send start bit
	while(!SSP1IF);		// Wait for it to complete
	SSP1IF = 0;			// Clear the flag bit
}


// Function Purpose: I2C_ReStart sends start bit sequence
void I2C_ReStart(void)
{
	RSEN = 1;			// Send Restart bit
	while(!SSP1IF);		// Wait for it to complete
	SSP1IF = 0;			// Clear the flag bit
}

void I2C_Send(unsigned char byte){ //slave'e byte data gönderdik
	
	I2C1TRN=byte; //Eğer adres bit 0 = 0 ise yazma için, 1 se okuma gibi

	while (I2C1STATbits.TRSTAT)
	{
		;	
	}//işte aktarım tamamlancak
	
	if (I2C1STATbits.ACKSTAT) //sonra eğer high ise bu ack = false
	{
		//
		while(1){ }// burda sıkışcak infinite loop ta, chip does not ack back
	}
	
}


//Function : I2C_Stop sends stop bit sequence
void I2C_Stop(void)
{
	PEN = 1;			// Send stop bit
	while(!SSP1IF);		// Wait for it to complete
	SSP1IF = 0;			// Clear the flag bit
}



//Function : I2C_Send_ACK sends ACK bit sequence
void I2C_Send_ACK(void)
{
	ACKDT = 0;			// 0 means ACK
	ACKEN = 1;			// Send ACKDT value
	while(!SSP1IF);		// Wait for it to complete
	SSP1IF = 0;			// Clear the flag bit
}


//Function : I2C_Send_NACK sends NACK bit sequence
void I2C_Send_NACK(void)
{
	ACKDT = 1;			// 1 means NACK
	ACKEN = 1;			// Send ACKDT value
	while(!SSP1IF);		// Wait for it to complete
	SSP1IF = 0;			// Clear the flag bit
}


// Function Purpose: I2C_Write_Byte transfers one byte
int I2C_Write_Byte(unsigned int Byte)
{
	SSP1BUF = Byte;		// Send Byte value
	while(!SSP1IF);		// Wait for it to complete
	SSP1IF = 0;			// Clear the flag bit

	return ACKSTAT;		// Return ACK/NACK from slave
}


// Function Purpose: I2C_Read_Byte reads one byte
unsigned char I2C_Read_Byte(void)
{
	RCEN = 1;			// Enable reception of 8 bits
	while(!SSP1IF);		// Wait for it to complete
	SSP1IF = 0;			// Clear the flag bit
 
    return SSPBUF;		// Return received byte
}
