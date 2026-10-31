
#include <iostream>
#include <iomanip>
#include "tasks.h"
#include "sensor.h"
#include "fusion.h"
#include "simulation_state.h"

using namespace std;

// Task 1: Generate sensor readings
void generateSensorReadings() {

    double actualDistance = 100.0;

    Sensor sensor1("Sensor 1", 2.0, 0.7);
    Sensor sensor2("Sensor 2", 5.0, 0.3);

    double reading1 = sensor1.generateReading(actualDistance);
    double reading2 = sensor2.generateReading(actualDistance);

    // Save the readings for all other tasks
    lastSimulation = {
        true,
        "Standard Sensor Readings",
        actualDistance,
        reading1,
        reading2,
        0.0,
        sensor1.getWeight(),
        sensor2.getWeight(),
        false
    };

    cout << fixed << setprecision(2);

    cout << "\n========== SENSOR READINGS ==========\n";

    cout << "Actual Distance: "
         << actualDistance << " cm\n";

    cout << "Sensor 1: "
         << reading1 << " cm\n";

    cout << "Sensor 2: "
         << reading2 << " cm\n";

    cout << "\nReadings saved successfully.\n";
}


// Task 2: Calculate fused estimate
void calculateFusedEstimate() {

    if (!lastSimulation.available) {
        cout << "\nNo sensor readings available.\n";
        cout << "Please run option 1 first.\n";
        return;
    }

    // Use the saved readings from option 1
    double fusedEstimate = FusionEngine::weightedAverage(
        lastSimulation.reading1,
        lastSimulation.weight1,
        lastSimulation.reading2,
        lastSimulation.weight2
    );

    // Save the result
    lastSimulation.fusedEstimate = fusedEstimate;
    lastSimulation.fusedAvailable = true;

    cout << fixed << setprecision(2);

    cout << "\n========== FUSED ESTIMATE ==========\n";

    cout << "Sensor 1 Reading: "
         << lastSimulation.reading1 << " cm\n";

    cout << "Sensor 2 Reading: "
         << lastSimulation.reading2 << " cm\n";

    cout << "Fused Estimate: "
         << fusedEstimate << " cm\n";
}
