
#ifndef TASKS_H
#define TASKS_H

// Diego's simulation functions
void generateSensorReadings();
void calculateFusedEstimate();

// Anthony's evaluation and scenario functions
void calculateEstimationErrors();
void runLowNoiseScenario();
void runHighNoiseScenario();
void runOutlierScenario();
void displaySimulationResults();

#endif
