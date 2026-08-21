Air Quality and Temperature Monitoring System using ESP32

An IoT-based Air Quality and Temperature Monitoring System using ESP32, MQ-135, DS18B20 and Firebase. The system collects air-quality and temperature data and displays the sensor readings on a web dashboard in real time.

Project Overview

This project is designed to monitor environmental conditions using an ESP32 microcontroller. The MQ-135 gas sensor is used for air-quality/gas-level monitoring, while the DS18B20 temperature sensor measures temperature.

The collected data is sent to Firebase Realtime Database through Wi-Fi. A web dashboard retrieves the data from Firebase and displays the readings.

Features

- Real-time temperature monitoring
- Air-quality/gas-level monitoring
- ESP32-based IoT system
- Firebase Realtime Database integration
- Web-based monitoring dashboard
- Buzzer/emergency indication
- Remote data monitoring through the internet

Hardware Components

- ESP32 Development Board
- MQ-135 Gas Sensor
- DS18B20 Temperature Sensor
- 4.7 kΩ Resistor
- Buzzer
- Power Supply
- Connecting Wires
- Breadboard

Software and Technologies

- Arduino IDE
- C/C++
- HTML
- CSS
- JavaScript
- Firebase Realtime Database
- ESP32 Wi-Fi

Working Principle

1. The ESP32 connects to a Wi-Fi network.
2. The MQ-135 sensor measures the air-quality/gas level.
3. The DS18B20 sensor measures the surrounding temperature.
4. ESP32 processes the sensor readings.
5. The collected data is sent to Firebase Realtime Database.
6. The web dashboard retrieves the latest data from Firebase.
7. Temperature, air-quality and emergency/buzzer status are displayed on the dashboard.
8. The system can be monitored remotely through the web interface.

System Architecture

MQ-135 ───────┐
              │
DS18B20 ──────┤
              ↓
           ESP32
              │
           Wi-Fi
              ↓
     Firebase Realtime Database
              │
              ↓
       Web Dashboard
              │
              ↓
     Real-Time Monitoring

Project Files

Air-Quality-Temperature-Monitoring-ESP32/
│
├── README.md
├── index.html
├── Project_Report.pdf
├── ESP32_Code/
├── Circuit_Diagram/
└── Results/

Results

The developed system successfully collects temperature and air-quality data using ESP32 and displays the information through a Firebase-connected web dashboard.

Applications

- Indoor air-quality monitoring
- Smart home monitoring
- Laboratory monitoring
- Office environment monitoring
- IoT-based environmental monitoring
- Industrial/environmental condition monitoring

Future Scope

- Integration of additional environmental sensors
- Mobile application development
- Cloud-based data analysis
- Historical data and graphical visualization
- SMS/email alerts
- Machine-learning-based air-quality prediction

Project Report

The complete project report is available in this repository:

Air_Quality_And_Temperature_Monitoring_System.pdf

Author

xxxxxxxxx

B.Tech – Electronics & Communication Engineering

Disclaimer

This project is developed for academic and educational purposes. The MQ-135 provides sensor-based gas/air-quality indications and should not be treated as a certified safety or medical measurement device.
