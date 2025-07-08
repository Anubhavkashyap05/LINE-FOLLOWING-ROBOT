# Smart Line Following Robot for Agriculture 🌱🤖

This Arduino-based robot is designed to autonomously follow lines and measure **soil moisture** and **temperature**, targeting smart farming applications. Built with IR sensors, DHT11, and a soil sensor, it can navigate predefined paths and collect real-time environmental data.

## 🔧 Features
- IR-based **line following**
- **Soil moisture** detection using analog sensor
- **Temperature & humidity** monitoring using DHT11
- Data output via Serial and Bluetooth
- Mechanical chassis designed using **Fusion 360**

## 🛠️ Hardware Used
- Arduino Uno
- L298N Motor Driver
- 2x BO Motors + Wheels
- IR Sensors (x2)
- Soil Moisture Sensor
- DHT11 Temperature & Humidity Sensor
- 18650 Li-ion Battery Pack (7–12V)
- Bluetooth Module (optional)
- Chassis: Custom-designed in Fusion 360

## ⚙️ Circuit Diagram
![Circuit Diagram](circuit_diagram.jpg)

## 💻 Arduino Code
The main code is in `line_following_agri_bot.ino`. It handles:
- Sensor calibration and data reading
- Differential motor control logic
- Moisture level detection
- DHT11 readings and Bluetooth output

## 🚀 Future Scope
- Add GPS for navigation across large farms
- Implement real-time data logging via SD card
- Use PID control for smoother line following
- Automate complete field coverage for crop health monitoring

## 📷 Images
Include hardware build photos here if available.

## 📜 License
This project is open-source for academic and personal use.
