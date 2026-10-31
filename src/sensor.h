
#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <random>

using namespace std;

class Sensor {
private:
    string name;
    double noiseLevel;
    double weight;

    mt19937 generator;

public:
    // Constructor
    Sensor(string sensorName, double noise, double sensorWeight);

    // Generate a simulated sensor reading
    double generateReading(double actualDistance);

    // Get sensor information
    double getWeight() const;
    string getName() const;
};

#endif
