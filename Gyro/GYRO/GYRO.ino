#include <Wire.h>
#include <Servo.h>
#include <MPU6050.h>
 
 MPU6050 mpu;
 Servo myservo;
 
void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(0);
  Serial.println("Inicjalizacja MPU6050");
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Mpu Init");
    delay(500);
  }

  mpu.calibrateGyro();
  mpu.setThreshold(3);
}
 
void loop()
{
  Vector rawGyro = mpu.readRawGyro();
  Vector normGyro = mpu.readNormalizeGyro();
 /*
  Serial.print(" Xraw = ");
  Serial.print(rawGyro.XAxis);
  Serial.print(" Yraw = ");
  Serial.print(rawGyro.YAxis);
  Serial.print(" Zraw = ");
  Serial.println(rawGyro.ZAxis);
 */
  Serial.print(" Xnorm = ");
  Serial.print(normGyro.XAxis);
  Serial.print(" Ynorm = ");
  Serial.print(normGyro.YAxis);
  Serial.print(" Znorm = ");
  Serial.println(normGyro.ZAxis);
  
  if(normGyro.XAxis>50)//change these angles according to you...
  {
  myservo.write(120);
  delay(5000);
  myservo.write(0);
  delay(500);
  }
  if(normGyro.XAxis<-50)//change these angles according to you...
  {
  myservo.write(120);
  delay(5000);
  myservo.write(0);
  delay(500);
  }
  if(normGyro.YAxis>50)//change these angles according to you...
  {
  myservo.write(120);
  delay(5000);
  myservo.write(0);
  delay(1000);
  }
  if(normGyro.YAxis<-50)//change these angles according to you...
  {
  myservo.write(120);
  delay(5000);
  myservo.write(0);
  delay(500);
  }
  if(normGyro.ZAxis>50)//change these angles according to you...
  {
  myservo.write(120);
  delay(5000);
  myservo.write(0);
  delay(500);
  }
  if(normGyro.ZAxis<-50)//change these angles according to you...
  {
  myservo.write(120);
  delay(5000);
  myservo.write(0);
  delay(500);
  }
 
  delay(2);
}
