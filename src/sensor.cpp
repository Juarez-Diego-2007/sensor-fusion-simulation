
#include "sensor.h"
#include <stdexcept>
#include <random>

// Constructor
Sensor::Sensor(string sensorName, double noise, double sensorWeight)
    : name(sensorName),
      noiseLevel(noise),
      weight(sensorWeight),
      generator(random_device{}()) {

    if (noiseLevel < 0 || weight <= 0) {
        throw invalid_argument("Noise must be nonnegative and weight must be positive.");
    }
}

// Generate a simulated sensor reading
double Sensor::generateReading(double actualDistance) {

    normal_distribution<double> distribution(0.0, noiseLevel);

    double randomNoise = distribution(generator);

    return actualDistance + randomNoise;
}

// Return sensor weight
double Sensor::getWeight() const {
    return weight;
}

// Return sensor name
string Sensor::getName() const {
    return name;
}
