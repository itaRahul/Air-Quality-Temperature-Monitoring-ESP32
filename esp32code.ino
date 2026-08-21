#include <WiFi.h>
#include <FirebaseESP32.h>
#include <ESP32Servo.h> //library for ESP32 Servo Control
// Firebase Configuration
#define FIREBASE_HOST "https://esp32-bcb2b-default-rtdb.asia-southeast1.firebasedatabase.app"
 //Stores Firebase database URL
#define FIREBASE_AUTH "eZ6d7yUjvO3AXk1uOV8BwwtOCZp7wsmXgGUJux86"//Stores authentication token for Firebase access
// Wi-Fi Credentials
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
// Servo Setup
Servo myServo; //Creates a Servo object to control a servo motor
#define SERVO_PIN 13 // Any PWM-capable GPIO pin
// Firebase Setup
FirebaseData firebaseData; //Object to handle Firebase data communication
FirebaseConfig config; //Configuration object for Firebase settings
FirebaseAuth auth; //Authentication object for Firebase login
void setup() 
{
    Serial.begin(9600);
	// Wi-Fi Connection
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) 
		{
        delay(500);
        Serial.print(".");
		}
    Serial.println("\nConnected to Wi-Fi");
	// Initialize Firebase
     config.host = FIREBASE_HOST; //Sets Firebase host URL.
    config.signer.tokens.legacy_token = FIREBASE_AUTH; //Sets Firebase authentication token
    Firebase.begin(&config, &auth); //Initializes Firebase connection
    Firebase.reconnectWiFi(true); //Automatically reconnects Wi-Fi if disconnected
    // Initialize Servo
    myServo.attach(SERVO_PIN); 
    myServo.write(90); // Default position
	  Serial.println("Setup completed.");
}
void loop() 
{  
  // Send Sensor Data
  int sensorValue = analogRead(34);  // Example sensor on GPIO34
  float voltage = (sensorValue * 3.3) / 4095.0;  // Conversion to 0 - 3.3V
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2); // Display 2 decimal places
  Serial.println(" V");
  Firebase.setInt(firebaseData, "/sensor/value", voltage);
    // Read Servo Position from Firebase
  if (Firebase.getInt(firebaseData, "/servo/position")) 
	{
        int servoPosition = firebaseData.intData();
        myServo.write(servoPosition);
        Serial.print("Servo Position: ");
        Serial.println(servoPosition);
  }
else
 {
        Serial.println("Failed to read servo position from Firebase.");
        Serial.println(firebaseData.errorReason());
  }
delay(1000);  // 1-second delay for stable updates
}		//end of loop function
