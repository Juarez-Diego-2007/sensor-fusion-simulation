#include "simulation.h"
#include "fusion.h"

Simulation::Simulation() : groundTruth(100.0), seed(42), rng(42) {
    // Default setup so the program runs immediately
    sensors.push_back(Sensor("Ultrasonic", 2.0, 1.0));
    sensors.push_back(Sensor("Infrared", 5.0, 0.4));
}

void Simulation::addSensor(const Sensor& s) { sensors.push_back(s); }
void Simulation::clearSensors() { sensors.clear(); samples.clear(); }
std::vector<Sensor>& Simulation::getSensors() { return sensors; }
const std::vector<Sensor>& Simulation::getSensors() const { return sensors; }

void Simulation::setGroundTruth(double v) { groundTruth = v; }
double Simulation::getGroundTruth() const { return groundTruth; }
void Simulation::setSeed(unsigned s) { seed = s; rng.seed(s); }
unsigned Simulation::getSeed() const { return seed; }

void Simulation::generateReadings(int numSamples) {
    // TODO (Diego): fill `samples` with numSamples readings from every sensor
    (void)numSamples;
}

void Simulation::fuseAll() {
    // TODO (Diego): set sample.fused for every sample using Fusion
}

const std::vector<Sample>& Simulation::getSamples() const { return samples; }
bool Simulation::hasSamples() const { return !samples.empty(); }
