import socket
import pandas as pd
from joblib import load
import pyttsx3
import time
from sklearn.preprocessing import MinMaxScaler
import struct 
from sklearn.metrics import accuracy_score
import logging
import subprocess


# Load the trained model and scaler
model = load('/media/raspberry/64E5-D9E51/tarek.pkl')
scaler = load('/media/raspberry/64E5-D9E51/scaler81.pkl')
le = load('/media/raspberry/64E5-D9E51/labelencoder81.pkl')

engine = pyttsx3.init()

# ESP32 IP address and port
HOST = '192.168.175.165'
PORT = 4444

# Function to receive sensor data from ESP32
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()
        with conn:
            while True:
                data = conn.recv(44)
               
                if not data:
                    break
                    
                
                angles = struct.unpack("5f", data[:20])# Assuming 3 floats for accelerometer
                gyro = struct.unpack('3f', data[20:32]) 
                accel = struct.unpack('3f', data[32:])
                


             
              
            
                angles_dict = {'flex_{}'.format(i+1): angle for i, angle in enumerate(angles)}
                gyro_dict = {'GYR{}'.format(i+1): gyro_value for i, gyro_value in enumerate(gyro)}
                accel_dict = {'ACC{}'.format(i+1): accel_value for i, accel_value in enumerate(accel)}

# Convert dictionaries to DataFrame
                df_angles = pd.DataFrame([angles_dict])
                df_gyro = pd.DataFrame([gyro_dict])
                df_accel = pd.DataFrame([accel_dict])

# Concatenate the three DataFrames along the columns axis
                df = pd.concat([df_angles,  df_gyro ,  df_accel], axis=1)
            
                df.columns = ['flex_1', 'flex_2', 'flex_3', 'flex_4', 'flex_5', 'GYRx', 'GYRy', 'GYRz', 'ACCx', 'ACCy', 'ACCz' ]

# Scale the data using scaler.transform



           
# Assuming accel_data and gyro_data are your accelerometer and gyroscope data


                # Scale the features
                scaled_data = scaler.transform(df)

                # Make prediction
                predicted_label = le.inverse_transform(model.predict(scaled_data))
                predicted_alphabet = predicted_label[0]
                print(f"Predicted alphabet: {predicted_alphabet}")
       
               

                




                time.sleep(1)  # Adjust the delay as needed

   
