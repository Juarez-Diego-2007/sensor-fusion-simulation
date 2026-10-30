#pragma once
#include <vector>
#include <random>
#include "sensor.h"

struct Sample {
    double truth;
    std::vector<double> readings;  // one per sensor
    double fused;
};

// Owns sensors, ground truth, RNG, and results (owner: Diego)
class Simulation {
public:
    Simulation();

    void addSensor(const Sensor& s);
    void clearSensors();
    std::vector<Sensor>& getSensors();
    const std::vector<Sensor>& getSensors() const;

    void setGroundTruth(double value);
    double getGroundTruth() const;
    void setSeed(unsigned s);
    unsigned getSeed() const;

    void generateReadings(int numSamples);  // T3
    void fuseAll();                          // T4
    const std::vector<Sample>& getSamples() const;
    bool hasSamples() const;

private:
    std::vector<Sensor> sensors;
    double groundTruth;
    unsigned seed;
    std::mt19937 rng;
    std::vector<Sample> samples;
};
