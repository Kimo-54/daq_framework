#pragma once
#include <iostream>
#include "Sensor.hpp"

class Pressure : public Sensor {
public:
    Pressure (int id) : Sensor (id) {}
    void read() const override { std::cout << "Pressure id = " <<id_ << "\n"; }
};