#include "FlexLibrary.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include "classifier.h"
Flex flex[5] = {Flex(36), Flex(39), Flex(34), Flex(35), Flex(32)}; // Analog pins the flex sensors are on
Adafruit_MPU6050 mpu;
Eloquent::ML::Port::RandomForest randomForest;
               
void setup() {
    Serial.begin(9600);
    while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

     mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }
   for (int i = 0; i < 5; i++) {
        
        for(int j = 0; j < 1000; j++){
            flex[i].Calibrate();
        }}
  }
void loop() {
    float angles[5];
    float x[11];
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    for (int i = 0; i < 5; i++) {
        flex[i].updateVal();
        float sensorValue = flex[i].getSensorValue();
        float minInput = flex[i].getMinInput();
        float maxInput = flex[i].getMaxInput();

        // Normalize flex sensor value
        if (maxInput > minInput) {
            x[i] = (sensorValue - minInput) / (maxInput);
        } else {
            x[i] = 0; 
        }
    }

    // Assign values for gyroscope and accelerometer
    x[5] = g.gyro.x; //* 57.2958;
    x[6] = g.gyro.y; //* 57.2958;
    x[7] = g.gyro.z ;//* 57.2958;
    x[8] = a.acceleration.x /9.81;
    x[9] = a.acceleration.y /9.81;
    x[10] = a.acceleration.z /9.81;

    // Make predictions
    int prediction = randomForest.predict(x);
    Serial.print("Prediction: ");
    Serial.println(prediction);
  
    const char* label = randomForest.predictLabel(x);
    Serial.print("Label: ");
    Serial.println(label);
  
    Serial.print("Normalized Flex Sensor Value: ");
    Serial.println(x[0]); 
    delay(1000); 
}
