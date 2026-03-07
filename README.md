# ELEE-1148 Smart Parking Lot Presence System Project
This project implements a Smart Parking Lot lighting concept designed to exemplify energy conservation. The system uses presence detection to trigger overhead lighting, with the LED intensity automatically adjusting based on real-time ambient light levels.

## Concept & Logic
The core idea is to provide levels of illumination that adapt to the environment:
* **Presence-Triggered:** The LED activates only when motion is detected within a specific threshold (e.g., < 16cm in this prototype).
* **Stay-On Timer:** Once triggered, the light maintains its state for 60 seconds after the last detected presence to ensure safety for the user
* **Adaptive Brightness:** To save energy, the system monitors ambient light
    - **Daylight:** If it is sufficiently bright, the LED remains OFF even if presence is detected
    - **Twilight/Darkness:** The LED gets progressively brighter as the environment gets darker, using PWM to manage energy output effectively.

## Hardware Components
* **Microcontroller:** Arduino Board (Uno R3)
* **Motion Sensor:** HC-SR04 Ultrasonic Distance Sensor
* **Light Sensor:** LDR (Photoresistor - MPY54C569)
* **Actuator:** LED Bulb
* **Resistors:**
    - **10kΩ** for the LDR voltage divider.
    - **220Ω**  for LED current limiting.

## Circuit Connections
**HC-SR04 Ultrasonic Sensor**
* **VCC:** 3.3V
* **GND:** GND
* **Echo:** Digital Pin 10 (PWM)
* **Trig:** Digital Pin 9 (PWM)

## LED Configuration
* **Anode:** Digital Pin 6 (PWM)
* **Cathode:**  Connected to a **220Ω** resistor, then to **GND**.

## LDR Configuration
* **Leg 1:** 5V (VCC)
* **Leg 2:** Connected to a junction point.
* **Junction:** Connects Leg 2 of LDR, Analog Pin A0, and the 10kΩ resistor.
* **Resistor Leg 2:** GND
  
---

## Current Limitations
* **Hardware Spikes:** Due to the nature of ultrasonic waves, the sensor may occasionally report out-of-context values (e.g., 1000cm+) if the signal fails to reflect. For best results, ensure objects are **flat and horizontal** to the sensor.
* **Calibration:** Current light thresholds (e.g., >=150) are placeholders used for testing logic; real-world calibration will be addressed in v1.1.
* **Conceptual Energy Saving: ** While brightness dimming saves power, the Arduino currently does not utilize interrupts or sleep modes. The energy conservation is currently conceptual. Implementing deep-sleep cycles and hardware-interrupt triggers is a major milestone targeted for v2.0.

##  Contributors
This project is a joint work with [@Fatmanur0001](https://github.com/Fatmanur0001). Both contributors are entitled to all claims and rights regarding the code and design.