#include "i2c_master.h"
#include "examples/i2c_master_example.h"

void MCP23008_Output(unsigned int condition)
{
    I2C_Open(0x40); // I2C Start condition
	
        I2C_WriteNBytes(0x40,0x00,1);  // Direction Register address        
        I2C_WriteNBytes(0x00,0x00,1);  // Make all GPIO Direction as output   
        I2C_WriteNBytes(0x80,0x00,1);  // Make all Input polarity register as o   
        I2C_WriteNBytes(0x00,0x00,1);  // Disable interrupt on change  
        I2C_WriteNBytes(0x40,0x00,1);  // Clear default value register  
        I2C_WriteNBytes(0x40,0x00,1);  // Clear interrupt control register  
        I2C_WriteNBytes(0x40,0x18,1);  // Configuration register, Slew register disabled 
        I2C_WriteNBytes(0x40,0xFF,1);  // Internal Pull-up enabled
        I2C_WriteNBytes(0x40,0x00,1);  // Interrupt flag register  
        I2C_WriteNBytes(0x40,0x00,1);  // Interrupt capture register   
        I2C_WriteNBytes(0x40,condition,1);  // GPIO
        I2C_Close();      
              // Stop  
//    I2C_Open(Address); // I2C Start condition	
//    while(I2C_Write_Byte(Address) == 1)// Wait until device is free
//    {	I2C_ReStart();	} // Start i2c communication       
//    I2C_WriteNBytes(Address,); //Device address with write command        
//    I2C_Write_Byte(0x00);  // Direction Register address        
//    I2C_Write_Byte(0x00);  // Make all GPIO Direction as output   
//    I2C_Write_Byte(0x00);  // Make all Input polarity register as o   
//    I2C_Write_Byte(0x00);  // Disable interrupt on change  
//    I2C_Write_Byte(0x00);  // Clear default value register  
//    I2C_Write_Byte(0x00);  // Clear interrupt control register  
//    I2C_Write_Byte(0x18);  // Configuration register, Slew register disabled 
//    I2C_Write_Byte(0xFF);  // Internal Pull-up enabled
//    I2C_Write_Byte(0x00);  // Interrupt flag register  
//    I2C_Write_Byte(0x00);  // Interrupt capture register   
//    I2C_Write_Byte(condition);  // GPIO
//    I2C_Close();            // Stop  
////        SSP1CON2bits.SEN = 1; // I2C Start condition	
//        I2C_Open();
////        while(I2C_Write(Address + 0) == 1)// Wait until device is free
////        {	SSP1CON2bits.RSEN = 1;	} // Start i2c communication       
//        I2C_Write(Address + 0); //Device address with write command        
//        I2C_Write(0x00);  // Direction Register address        
//        I2C_Write(0x00);  // Make all GPIO Direction as output   
//        I2C_Write(0x00);  // Make all Input polarity register as o   
//        I2C_Write(0x00);  // Disable interrupt on change  
//        I2C_Write(0x00);  // Clear default value register  
//        I2C_Write(0x00);  // Clear interrupt control register  
//        I2C_Write(0x18);  // Configuration register, Slew register disabled 
//        I2C_Write(0xFF);  // Internal Pull-up enabled
//        I2C_Write(0x00);  // Interrupt flag register  
//        I2C_Write(0x00);  // Interrupt capture register   
//        I2C_Write(condition);  // GPIO
//        I2C_Close();
////        SSP1CON2bits.PEN = 1;           // Stop  
}
////void Init_MCP23008(i2c_address_t address){
////     I2C_Open(address); // Issue start signal
////     I2C_WriteNBytes(address, 0x00,2);
////     I2C_WriteNBytes(address, 0x80,2);
////     I2C_WriteNBytes(address, 0x00,2);
////     I2C_WriteNBytes(address, 0x80,2);
////     I2C_WriteNBytes(address, 0x80,2);
////     I2C_WriteNBytes(address, 0x80,2);
////     I2C_Close();
////     
////     I2C_Open(address); // Issue start signal
////     I2C_WriteNBytes(address, 0x06,2);
////     I2C_WriteNBytes(address, 0x80,2);
////     I2C_Close();
////     
////     
////     
//////     
//////     
//////     I2C_Write_Byte(0x40); // Address + Write bit
//////     I2C_Write_Byte(0x00); // Select IODIR register
//////     I2C_Write_Byte(0x80); // GP0-GP6 O/P, GP7 I/P
//////     I2C_Write_Byte(0x00); // IPOL
//////     I2C_Write_Byte(0x80); // GP7 Interrupt-on-change
//////     I2C_Write_Byte(0x80); // GP7 Def value 1
//////     I2C_Write_Byte(0x80); // Interrupts on GP7 compares to DEFVAL
//////     I2C_Write_Byte(0x22); // Disable further sequential write operation
//////     I2C_Stop();
//////
//////     // Enable pull-up on GP7
//////     I2C_Start(); // Issue start signal
//////     I2C_Write_Byte(0x40); // Address + Write bit
//////     I2C_Write_Byte(0x06); // Select IODIR register
//////     I2C_Write_Byte(0x80); // GP7 pull-up
//////     I2C_Stop();
//// 
//}

void Init_MCP23008(){
 Delay_ms(10);
 I2C_Start();     // Issue start signal
 I2C_Write(0x40); // Slave Address + Write bit
 I2C_Write(0x00); // Select IODIR register
 I2C_Write(0x80); // GP0-GP6 O/P, GP7 I/P
 I2C_Write(0x00); // IPOL
 I2C_Write(0x80); // GP7 Interrupt-on-change
 I2C_Write(0x80); // GP7 Def value 1
 I2C_Write(0x22); // Disable further sequential write operation
 I2C_Stop();
// Enable resister pull-up on GP7
 I2C_Start();     // Issue start signal
 I2C_Write(0x40); // Address + Write bit
 I2C_Write(0x06); // Select IODIR register
 I2C_Write(0x80); // GP7 pull-up
 I2C_Stop();
}