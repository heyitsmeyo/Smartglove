#include <WiFi.h>
#include "FlexLibrary.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#define VCC 5.0// Voltage supplied to the flex sensors
#define R_DIV 10000.0  // Resistance of the resistor in series with the flex sensors
#define flatResistance 32500.0  // Resistance of the flex sensors when flat
#define bendResistance 76000.0  // Resistance of the flex sensors when bent

Flex flex[5] = {Flex(36), Flex(39), Flex(34), Flex(35), Flex(32)}; // Analog pins the flex sensors are on


const char* ssid = "";
const char* password = "";
const char* host ="";  // Raspberry Pi IP address
const int port = 4444;

WiFiClient client;
Adafruit_MPU6050 mpu;

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

  Serial.println("");
  delay(100);
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting...");
    }
    Serial.println("Connected to WiFi");

    Serial.println("Connecting to server...");
    if (client.connect(host, port)) {
        Serial.println("Connected to server");
    } else {
        Serial.println("Connection failed");
    }

    
}
void loop() {
    float angles[5];
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 1000; j++){
        flex[i].Calibrate();
  }
        flex[i].updateVal();
       
        float Vflex = flex[i].getSensorValue() * VCC / 4095.0;
        float Rflex = R_DIV * (VCC / Vflex - 1.0);

        angles[i] = map(Rflex, flatResistance, bendResistance, 0, 90);
        if(angles[i]<0){
          angles[i]=0;
        }
       // Serial.println(angles[i]);
    }


    byte data[sizeof(float) * 5 + sizeof(float) * 3 + sizeof(float) * 3];

  
    memcpy(data, angles, sizeof(float) * 5);

    
    memcpy(data + sizeof(float) * 8, &g.gyro.x, sizeof(float));
    memcpy(data + sizeof(float) * 9, &g.gyro.y, sizeof(float));
    memcpy(data + sizeof(float) * 10, &g.gyro.z, sizeof(float));
    memcpy(data + sizeof(float) * 5, &a.acceleration.x, sizeof(float));
    memcpy(data + sizeof(float) * 6, &a.acceleration.y, sizeof(float));
    memcpy(data + sizeof(float) * 7, &a.acceleration.z, sizeof(float));
   

    if (client.connected()) {
        client.write(data, sizeof(data));
    } else {
        Serial.println("Connection to server lost. Reconnecting...");
        if (client.connect(host, port)) {
            Serial.println("Reconnected to server");
            client.write(data, sizeof(data));
        } else {
            Serial.println("Reconnection failed");
        }
    }
/*Serial.print(g.gyro.x);
Serial.print("\n");
Serial.print(g.gyro.x);
Serial.print("\n");
Serial.print(g.gyro.x);
Serial.print("\n");
Serial.print(a.acceleration.x);
Serial.print("\n");
Serial.print(a.acceleration.y);
Serial.print("\n");
Serial.print(a.acceleration.z);
Serial.print("\n");*/
    delay(1000);  // Adjust delay as needed
}
