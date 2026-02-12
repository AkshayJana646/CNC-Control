#include <Arduino.h>
#include <Utils/Astra.h>
#include <Sensors/HW/Accel/ADXL375.h>
#include "CncState.h"

using namespace astra;

// Instantiate high-g accelerometer
ADXL375 highGAccel("HighG", &Wire, 0x1D);

// CNC controller
CncState cncState;

void setup() {
    Serial.begin(115200);

    // Initialize accelerometer
    highGAccel.begin();
    highGAccel.setUpdateRate(50); // 50 Hz

    // Link accelerometer to CNC state
    cncState.accelSensor = &highGAccel;
}

void loop() {
    // Read accelerometer directly
    Vector<3> accel = cncState.accelSensor->getAccel();
    cncState.updateCncState();


    delay(100);  // simple loop delay
}

