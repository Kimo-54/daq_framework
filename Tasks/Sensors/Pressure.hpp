#pragma once
#include <iostream>
#include "Sensor.hpp"

class Pressure : public Sensor {
public:
    Pressure (int id) : Sensor (id) {}
    void read() override { std::cout << "Pressure id = " <<id_ << std::endl; }
};