
#include "tasks.h"
#include "evaluator.h"
#include "sensor.h"
#include "fusion.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Store the results of the most recent simulation
struct LastSimulation {
    bool available = false;
    string scenario;
    double actualDistance = 0;
    double reading1 = 0;
    double reading2 = 0;
    double fusedEstimate = 0;
    double weight1 = 0;
    double weight2 = 0;
};

static LastSimulation lastSimulation;


// ============================================
// TASK 3: CALCULATE ESTIMATION ERRORS
// ============================================

void calculateEstimationErrors() {

    double actualDistance = 100.0;

    // Create two sensors with different noise levels
    Sensor sensor1("Sensor 1", 2.0, 0.7);
    Sensor sensor2("Sensor 2", 5.0, 0.3);

    // Generate readings from the same actual distance
    double reading1 = sensor1.generateReading(actualDistance);
    double reading2 = sensor2.generateReading(actualDistance);

    // Calculate the fused estimate
    double fusedEstimate = FusionEngine::weightedAverage(
        reading1, sensor1.getWeight(),
        reading2, sensor2.getWeight()
    );

    // Save the results for option 7
    lastSimulation = {
        true,
        "Estimation Errors",
        actualDistance,
        reading1,
        reading2,
        fusedEstimate,
        sensor1.getWeight(),
        sensor2.getWeight()
    };

    // Display simulation information
    cout << fixed << setprecision(2);

    cout << "\n========== ESTIMATION ERRORS ==========\n";

    cout << "Actual Distance: "
         << actualDistance << " cm\n";

    cout << "Sensor 1 Reading: "
         << reading1 << " cm\n";

    cout << "Sensor 2 Reading: "
         << reading2 << " cm\n";

    cout << "Fused Estimate: "
         << fusedEstimate << " cm\n";

    // Calculate and compare errors
    Evaluation evaluation(
        actualDistance,
        reading1,
        reading2,
        fusedEstimate
    );

    evaluation.printReport();
}


// ============================================
// TASK 4: RUN LOW-NOISE SCENARIO
// ============================================

void runLowNoiseScenario() {

    double actualDistance = 100.0;

    // Create sensors with low noise levels
    Sensor sensor1("Sensor 1", 0.5, 0.7);
    Sensor sensor2("Sensor 2", 1.0, 0.3);

    // Generate sensor readings
    double reading1 = sensor1.generateReading(actualDistance);
    double reading2 = sensor2.generateReading(actualDistance);

    // Calculate weighted-average fused estimate
    double fusedEstimate = FusionEngine::weightedAverage(
        reading1, sensor1.getWeight(),
        reading2, sensor2.getWeight()
    );

    // Save the results for option 7
    lastSimulation = {
        true,
        "Low-Noise Scenario",
        actualDistance,
        reading1,
        reading2,
        fusedEstimate,
        sensor1.getWeight(),
        sensor2.getWeight()
    };

    // Display simulation information
    cout << "\n========== LOW-NOISE SCENARIO ==========\n";

    cout << fixed << setprecision(2);

    cout << "Actual Distance: "
         << actualDistance << " cm\n";

    cout << "Sensor 1 Reading: "
         << reading1 << " cm\n";

    cout << "Sensor 2 Reading: "
         << reading2 << " cm\n";

    cout << "Fused Estimate: "
         << fusedEstimate << " cm\n";

    // Calculate and display errors
    Evaluation evaluation(
        actualDistance,
        reading1,
        reading2,
        fusedEstimate
    );

    evaluation.printReport();
}


// ============================================
// TASK 5: RUN HIGH-NOISE SCENARIO
// ============================================

void runHighNoiseScenario() {

    double actualDistance = 100.0;

    // Create sensors with high noise levels
    Sensor sensor1("Sensor 1", 8.0, 0.7);
    Sensor sensor2("Sensor 2", 15.0, 0.3);

    // Generate sensor readings
    double reading1 = sensor1.generateReading(actualDistance);
    double reading2 = sensor2.generateReading(actualDistance);

    // Calculate weighted-average fused estimate
    double fusedEstimate = FusionEngine::weightedAverage(
        reading1, sensor1.getWeight(),
        reading2, sensor2.getWeight()
    );

    // Save the results for option 7
    lastSimulation = {
        true,
        "High-Noise Scenario",
        actualDistance,
        reading1,
        reading2,
        fusedEstimate,
        sensor1.getWeight(),
        sensor2.getWeight()
    };

    // Display simulation information
    cout << "\n========== HIGH-NOISE SCENARIO ==========\n";

    cout << fixed << setprecision(2);

    cout << "Actual Distance: "
         << actualDistance << " cm\n";

    cout << "Sensor 1 Reading: "
         << reading1 << " cm\n";

    cout << "Sensor 2 Reading: "
         << reading2 << " cm\n";

    cout << "Fused Estimate: "
         << fusedEstimate << " cm\n";

    // Calculate and display errors
    Evaluation evaluation(
        actualDistance,
        reading1,
        reading2,
        fusedEstimate
    );

    evaluation.printReport();
}


// ============================================
// TASK 6: RUN OUTLIER SCENARIO
// ============================================

void runOutlierScenario() {

    double actualDistance = 100.0;

    // Create two sensors with different noise levels
    Sensor sensor1("Sensor 1", 2.0, 0.7);
    Sensor sensor2("Sensor 2", 5.0, 0.3);

    // Generate sensor readings
    double reading1 = sensor1.generateReading(actualDistance);
    double reading2 = sensor2.generateReading(actualDistance);

    // Simulate a faulty sensor with a large added error
    reading2 += 40.0;

    // Calculate the fused estimate
    double fusedEstimate = FusionEngine::weightedAverage(
        reading1, sensor1.getWeight(),
        reading2, sensor2.getWeight()
    );

    // Save the results for option 7
    lastSimulation = {
        true,
        "Outlier Scenario (Sensor 2 Faulty)",
        actualDistance,
        reading1,
        reading2,
        fusedEstimate,
        sensor1.getWeight(),
        sensor2.getWeight()
    };

    // Display simulation information
    cout << "\n========== OUTLIER SCENARIO ==========\n";

    cout << fixed << setprecision(2);

    cout << "Actual Distance: "
         << actualDistance << " cm\n";

    cout << "Sensor 1 Reading: "
         << reading1 << " cm\n";

    cout << "Sensor 2 Reading (Faulty): "
         << reading2 << " cm\n";

    cout << "Fused Estimate: "
         << fusedEstimate << " cm\n";

    cout << "\nWARNING: Sensor 2 contains an artificial "
         << "40 cm measurement error.\n";

    // Calculate and compare errors
    Evaluation evaluation(
        actualDistance,
        reading1,
        reading2,
        fusedEstimate
    );

    evaluation.printReport();
}


// ============================================
// TASK 7: DISPLAY SIMULATION RESULTS
// ============================================

void displaySimulationResults() {

    // Check whether a simulation has been run
    if (!lastSimulation.available) {

        cout << "\nNo simulation results available.\n";

        cout << "Please run option 3, 4, 5, or 6 first.\n";

        return;
    }

    cout << fixed << setprecision(2);

    cout << "\n========== SIMULATION RESULTS ==========\n";

    cout << "Scenario: "
         << lastSimulation.scenario << "\n";

    cout << "Actual Distance: "
         << lastSimulation.actualDistance << " cm\n";

    cout << "Sensor 1 Reading: "
         << lastSimulation.reading1 << " cm\n";

    cout << "Sensor 2 Reading: "
         << lastSimulation.reading2 << " cm\n";

    cout << "Sensor 1 Weight: "
         << lastSimulation.weight1 << "\n";

    cout << "Sensor 2 Weight: "
         << lastSimulation.weight2 << "\n";

    cout << "Fused Estimate: "
         << lastSimulation.fusedEstimate << " cm\n";

    // Calculate errors using the saved readings
    Evaluation evaluation(
        lastSimulation.actualDistance,
        lastSimulation.reading1,
        lastSimulation.reading2,
        lastSimulation.fusedEstimate
    );

    evaluation.printReport();
}
