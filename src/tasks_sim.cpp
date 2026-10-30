
#include <iostream>
#include "tasks.h"
#include "sensor.h"
#include "fusion.h"

using namespace std;

// Task 1: Generate sensor readings
void generateSensorReadings() {

    double actualDistance = 100.0;

    Sensor sensor1("Sensor 1", 2.0, 0.7);
    Sensor sensor2("Sensor 2", 5.0, 0.3);

    double reading1 = sensor1.generateReading(actualDistance);
    double reading2 = sensor2.generateReading(actualDistance);

    cout << "\nSensor 1: " << reading1 << " cm" << endl;
    cout << "Sensor 2: " << reading2 << " cm" << endl;
}

// Task 2: Calculate fused estimate
void calculateFusedEstimate() {

    double actualDistance = 100.0;

    Sensor sensor1("Sensor 1", 2.0, 0.7);
    Sensor sensor2("Sensor 2", 5.0, 0.3);

    double reading1 = sensor1.generateReading(actualDistance);
    double reading2 = sensor2.generateReading(actualDistance);

    double fusedEstimate = FusionEngine::weightedAverage(
        reading1, sensor1.getWeight(),
        reading2, sensor2.getWeight()
    );

    cout << "\nFused Estimate: "
         << fusedEstimate << " cm" << endl;
}
