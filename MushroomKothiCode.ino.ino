#include "DHT.h"

// Define the sensor and relay pins
#define DHTPIN 14            // DHT22 sensor data pin connected to GPIO14
#define DHTTYPE DHT22        // We're using DHT22
#define FAN_RELAY 2          // Fan relay connected to GPIO2
#define HUMIDIFIER_RELAY 4   // Humidifier relay connected to GPIO4

// Initialize the sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);      // Start the Serial Monitor
  dht.begin();               // Start the DHT sensor

  pinMode(FAN_RELAY, OUTPUT);
  pinMode(HUMIDIFIER_RELAY, OUTPUT);

  // Make sure both devices are OFF initially
  digitalWrite(FAN_RELAY, LOW);
  digitalWrite(HUMIDIFIER_RELAY, LOW);
}

void loop() {
  // Read temperature and humidity from sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if the readings are valid
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("⚠️ Sensor error: Failed to read from DHT22!");
    delay(1000);
    return;
  }

  // Display current readings
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Logic to control the fan
  if (temperature > 28.0) {
    digitalWrite(FAN_RELAY, HIGH); // Turn fan ON
    Serial.println("Fan: ON");
  } else {
    digitalWrite(FAN_RELAY, LOW);  // Turn fan OFF
    Serial.println("Fan: OFF");
  }

  // Logic to control the humidifier
  if (humidity < 70.0) {
    digitalWrite(HUMIDIFIER_RELAY, HIGH); // Turn humidifier ON
    Serial.println("Humidifier: ON");
  } else {
    digitalWrite(HUMIDIFIER_RELAY, LOW);  // Turn humidifier OFF
    Serial.println("Humidifier: OFF");
  }

  Serial.println("--------------------------");

  delay(1000);  // Wait for a second before reading again
}
