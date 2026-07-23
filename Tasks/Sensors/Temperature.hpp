#pragma once
#include <iostream>
#include "Sensor.hpp"

class Temperature : public Sensor {
public:
    Temperature (int id) : Sensor (id) {}
    void read() override { std::cout << "Temperature id = " <<id_ << std::endl; }
    
};