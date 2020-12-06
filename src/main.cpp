#include "mbed.h"
#include "SHT3x.h"
#include "MPU6050.h"

SHT3x Sensor;
MPU6050 mpu6050;
Serial pc(USBTX, USBRX); 
pc.baud(19200);
Sensor.Begin();

   
int main(){
 
  //Set up I2C
  i2c.frequency(400000);  // use fast (400 kHz) I2C   

  while(1){

    Sensor.UpdateData();

    uint8_t whoami = mpu6050.readByte(MPU6050_ADDRESS, WHO_AM_I_MPU6050);  // Read WHO_AM_I register for MPU-6050
    pc.printf("I AM 0x%x\n\r", whoami);

    pc.print("Temperature: ");
    pc.print(Sensor.GetTemperature());
    pc.write("\xC2\xB0"); //The Degree symbol
    pc.println("C");
    pc.print("Humidity: ");
    pc.print(Sensor.GetRelHumidity());
    pc.println("%");

    delay(333);
  }
}