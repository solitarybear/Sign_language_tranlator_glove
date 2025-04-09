# ✋ Sign Language Translator Glove – ESP32 + Flex Sensors + IMU

A wearable glove project using **flex sensors**, an **IMU sensor**, and an **ESP32** microcontroller to detect hand gestures and translate them into human-readable text—displayed directly on the **Serial Monitor**.

This project aims to help bridge communication gaps by interpreting sign language gestures in real-time.

---

## 🎯 Objective

To create a low-cost, efficient **Sign Language Translator Glove** that converts hand gestures into text, enabling better communication for individuals with hearing or speech impairments.

---

## 📦 Components Required

| Component             | Quantity |
|----------------------|----------|
| ESP32 Dev Board      | 1        |
| Flex Sensors         | 5        |
| MPU6050 (IMU Sensor) | 1        |
| Resistors (10kΩ)     | 5        |
| Breadboard & Wires   | As needed |
| Glove (any fabric)   | 1        |

---

## 🧠 How It Works

- **Flex Sensors** detect the bending of each finger.
- **MPU6050 IMU** captures orientation and hand tilt data.
- ESP32 reads all inputs and matches gesture data to predefined patterns.
- The matched gesture is printed as **text output** on the Serial Monitor.

---

## ⚙️ Installation & Setup

### 1. 🧪 Library Dependencies

Install the following libraries in your Arduino IDE:

- `Wire.h` – For I2C communication
- `Adafruit_MPU6050` (or equivalent)
- `Adafruit_Sensor`
- Any custom logic for gesture mapping (in-code)

### 2. 🚀 Upload Code

- Open `translator_glove.ino` in the Arduino IDE.
- Select the appropriate ESP32 board and COM port.
- Upload the code.

### 3. 🖥️ Monitor Output

- Open the Serial Monitor at `9600` baud.
- Move your fingers to form specific gestures.
- The recognized word or phrase will be printed.

---

## 🔍 Example Output

```text
Gesture Recognized: HELLO
Gesture Recognized: THANK YOU
Gesture Recognized: YES
Gesture Recognized: NO
