#pragma once
#include <iostream>
#include "Sensor.hpp"

class mA : public Sensor {
public:
    mA (int id) : Sensor (id) {}
    void read() const override { std::cout << "mA id = " <<id_ << "\n"; }
};
