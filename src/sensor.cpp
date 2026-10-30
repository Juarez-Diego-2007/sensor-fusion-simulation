#include "sensor.h"
#include <iostream>
#include <iomanip>

Sensor::Sensor(const std::string& n, double noise, double w)
    : name(n), noiseStdDev(noise), weight(w), outlierChance(0.0), failed(false) {}

double Sensor::read(double trueValue, std::mt19937& rng) const {
    // TODO (Diego): add Gaussian noise, occasional outliers, handle failure
    (void)rng;
    return trueValue;
}

void Sensor::print() const {
    std::cout << std::left << std::setw(12) << name
              << " noise=" << noiseStdDev << " weight=" << weight
              << " outlier=" << outlierChance
              << (failed ? " [FAILED]" : "") << "\n";
}

const std::string& Sensor::getName() const { return name; }
double Sensor::getNoise() const { return noiseStdDev; }
double Sensor::getWeight() const { return weight; }
double Sensor::getOutlierChance() const { return outlierChance; }
bool Sensor::isFailed() const { return failed; }
void Sensor::setNoise(double s) { noiseStdDev = s; }
void Sensor::setWeight(double w) { weight = w; }
void Sensor::setOutlierChance(double p) { outlierChance = p; }
void Sensor::setFailed(bool f) { failed = f; }
