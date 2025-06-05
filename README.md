# 🍄 Mushroom Kothi – Smart Environment Control for Mushroom Cultivation

## 🌱 Overview

**Mushroom Kothi** is an IoT-based smart environment monitoring and control system designed for a 10x10 ft mushroom cultivation room. This prototype simulates a real-world solution that ensures optimal temperature and humidity using low-cost components and automation logic.

## 🔧 Components Used (Simulated in Wokwi)
- ESP32 Development Board
- DHT22 Temperature & Humidity Sensor
- 2x Relay Modules (simulated using LEDs)
  - LED1: Fan Control
  - LED2: Humidifier Control
- Serial Monitor for real-time data display

## 💡 Functional Logic
- 🌡️ If **temperature > 28°C**, the **Fan** (LED1) turns ON.
- 💧 If **humidity < 70%**, the **Humidifier** (LED2) turns ON.
- 📊 Temperature and humidity values are updated every second on the Serial Monitor.

## 🔌 Circuit Connections

| Component        | ESP32 Pin         | Notes                            |
|------------------|-------------------|----------------------------------|
| DHT22 VCC        | 3.3V              | Power Supply                     |
| DHT22 GND        | GND               | Ground                           |
| DHT22 DATA       | GPIO 14           | Data signal to ESP32             |
| LED1 (Fan Relay) | GPIO 26           | Controls Fan (via relay or LED)  |
| LED2 (Humidifier Relay) | GPIO 27    | Controls Humidifier (via relay)  |
| LED1 Anode       | GPIO 26 → 220Ω → + | Current-limiting resistor        |
| LED2 Anode       | GPIO 27 → 220Ω → + | Same as above                    |
| LED1 & LED2 Cathode | GND           | Connect to Ground                |

> In a real implementation, replace LEDs with **relay modules** connected to the fan and humidifier safely.

## 🌐 Wokwi Simulation
👉 [View Wokwi Simulation](https://wokwi.com/projects/432744739265751041)

## 🧠 Applications
- Mushroom farming automation
- Controlled environment agriculture (CEA)
- Low-cost climate monitoring systems for rural farmers

## 🛠 Future Enhancements
- Add CO₂ sensor (e.g., MH-Z19B)
- Cloud integration for data logging and alerts (Firebase, ThingSpeak)
- Mobile app UI for live monitoring and manual controls
- Solar-powered version for remote locations

## 📸 Screenshots
![Wokwi Circuit Screenshot ](https://github.com/user-attachments/assets/6ec84daa-2505-4c4f-bd3e-069dd59ff977)

## 🤝 Acknowledgements
- Wokwi.com for simulation platform
- DHT sensor library by Adafruit
- Mushroom growers and IoT communities for inspiration

---

> For questions or suggestions, feel free to open an issue or fork the repo!
