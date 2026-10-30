#pragma once
#include <string>
#include <random>

// One simulated sensor (owner: Diego)
class Sensor {
public:
    Sensor(const std::string& name, double noiseStdDev, double weight);

    double read(double trueValue, std::mt19937& rng) const;  // T3
    void print() const;

    const std::string& getName() const;
    double getNoise() const;
    double getWeight() const;
    double getOutlierChance() const;
    bool isFailed() const;

    void setNoise(double stdDev);
    void setWeight(double w);
    void setOutlierChance(double p);
    void setFailed(bool f);

private:
    std::string name;
    double noiseStdDev;    // standard deviation of Gaussian noise
    double weight;         // reliability weight used by fusion
    double outlierChance;  // probability (0-1) of a large bad reading
    bool failed;           // failed sensors are skipped by fusion
};
