#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

const int flexPins[5] = {34, 35, 32, 33, 36}; // Thumb, Index, Middle, Ring, Pinky

int flexValues[5];

void setup() {
  Serial.begin(115200);
  Wire.begin();

  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  } else {
    Serial.println("✅ MPU6050 connected.");
  }

  for (int i = 0; i < 5; i++) {
    pinMode(flexPins[i], INPUT);
  }

  Serial.println("🧤 Sign Language Translator Glove Ready!");
  delay(1000);
}

void loop() {
  // Read all 5 flex sensors
  for (int i = 0; i < 5; i++) {
    flexValues[i] = analogRead(flexPins[i]);
  }

  printFlexValues();
  detectGesture();

  delay(1000);
}

void printFlexValues() {
  Serial.println("----- FLEX SENSOR VALUES -----");
  for (int i = 0; i < 5; i++) {
    Serial.print("Finger ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(flexValues[i]);
  }
}

void detectGesture() {
  Serial.println("----- GESTURE DETECTION -----");

  // Example Ranges (you may need to calibrate for your hand)
  if (isFist()) {
    Serial.println("🖐 Detected Sign A: Fist (Hello)");
  } else if (isPalmOpen()) {
    Serial.println("✋ Detected Sign B: Open Palm (Goodbye)");
  } else if (isThumbsUp()) {
    Serial.println("👍 Detected Sign C: Thumbs Up (Yes)");
  } else if (isThumbsDown()) {
    Serial.println("👎 Detected Sign D: Thumbs Down (No)");
  } else if (isPeaceSign()) {
    Serial.println("✌️ Detected Sign E: Peace");
  } else if (isOKSign()) {
    Serial.println("👌 Detected Sign F: OK");
  } else if (isIndexPointing()) {
    Serial.println("👉 Detected Sign G: Pointing");
  } else if (isRockSign()) {
    Serial.println("🤘 Detected Sign H: Rock On");
  } else if (isThreeFingersUp()) {
    Serial.println("🖖 Detected Sign I: Live Long (3-fingers up)");
  } else if (isOnlyPinky()) {
    Serial.println("🤙 Detected Sign J: Call Me (Only Pinky)");
  } else {
    Serial.println("❓ Unknown Gesture");
  }

  Serial.println("-----------------------------\n");
}

// 🔍 Helper functions (flexValues[] indexes: 0=Thumb, 1=Index, ..., 4=Pinky)
bool isFist() {
  return allBent();
}

bool isPalmOpen() {
  return allStraight();
}

bool isThumbsUp() {
  return isStraight(0) && allBentExcept(0);
}

bool isThumbsDown() {
  return isBent(0) && allStraightExcept(0);
}

bool isPeaceSign() {
  return isStraight(1) && isStraight(2) && isBent(0) && isBent(3) && isBent(4);
}

bool isOKSign() {
  return isBent(0) && isBent(1) && isStraight(2) && isStraight(3) && isStraight(4);
}

bool isIndexPointing() {
  return isStraight(1) && allBentExcept(1);
}

bool isRockSign() {
  return isStraight(1) && isStraight(4) && isBent(0) && isBent(2) && isBent(3);
}

bool isThreeFingersUp() {
  return isStraight(1) && isStraight(2) && isStraight(3) && isBent(0) && isBent(4);
}

bool isOnlyPinky() {
  return isStraight(4) && allBentExcept(4);
}

// 📏 Sensor value logic
bool isBent(int i) {
  return flexValues[i] > 2500; // You may adjust this threshold
}

bool isStraight(int i) {
  return flexValues[i] < 1500;
}

bool allBent() {
  for (int i = 0; i < 5; i++) {
    if (!isBent(i)) return false;
  }
  return true;
}

bool allStraight() {
  for (int i = 0; i < 5; i++) {
    if (!isStraight(i)) return false;
  }
  return true;
}

bool allBentExcept(int skip) {
  for (int i = 0; i < 5; i++) {
    if (i == skip) continue;
    if (!isBent(i)) return false;
  }
  return true;
}

bool allStraightExcept(int skip) {
  for (int i = 0; i < 5; i++) {
    if (i == skip) continue;
    if (!isStraight(i)) return false;
  }
  return true;
}
