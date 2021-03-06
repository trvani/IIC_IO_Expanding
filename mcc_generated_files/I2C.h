/* 
 * File:   I2C.h
 * Author: Satheesh
 *
 * Created on September 30, 2016, 9:52 AM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif


// Define i2c pins
#define SDA			RB4				// Data pin for i2c
#define SCK			RB6				// Clock pin for i2c
#define SDA_DIR		TRISB4			// Data pin direction
#define SCK_DIR		TRISB6			// Clock pin direction

// Define i2c speed
#define I2C_SPEED	100				// kbps

//Function Declarations
void InitI2C(void);
void I2C_Start(void);
void I2C_ReStart(void);
void I2C_Stop(void);
void I2C_Send_ACK(void);
void I2C_Send_NACK(void);
int  I2C_Write_Byte(unsigned int);
unsigned char I2C_Read_Byte(void);



#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

