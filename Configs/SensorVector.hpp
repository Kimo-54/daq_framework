#pragma once

#include "../Infrastructure/ThreadSafeQueue/ThreadSafeQueue.hpp"
#include "../Tasks/Sensors/Sensor.hpp"
#include "../Tasks/Sensors/Temperature.hpp"
#include "../Tasks/Sensors/Pressure.hpp"
#include "../Tasks/Sensors/mA.hpp"

class SensorVector
{
    private:
    /* data */
    public:
        SensorVector(/* args */);
        ~SensorVector();
        void MainExTask()
        {
            // C-style array of raw pointers
            //Sensor* sensor_vec[] = { new Temperature(), new Pressure(), new Temperature() };
            //for (auto* a : sensor_vec) a->read();
            // ...and you have to delete each one later

            // Better: std::vector of smart pointers, cleans itself up

            std::vector<std::unique_ptr<Sensor>> sensor_vec;

            std::unique_ptr<Temperature> Temperature_138 = std::make_unique<Temperature>(138);
            std::unique_ptr<Pressure> Pressure_138 = std::make_unique<Pressure>(138);
            std::unique_ptr<mA> mA_138 = std::make_unique<mA>(138);
            sensor_vec.push_back(std::move(Temperature_138));
            sensor_vec.push_back(std::move(Pressure_138));
            sensor_vec.push_back(std::move(mA_138));

            std::unique_ptr<Temperature> Temperature_205 = std::make_unique<Temperature>(205);
            std::unique_ptr<Pressure> Pressure_205 = std::make_unique<Pressure>(205);
            std::unique_ptr<mA> mA_205 = std::make_unique<mA>(205);
            sensor_vec.push_back(std::move(Temperature_205));
            sensor_vec.push_back(std::move(Pressure_205));
            sensor_vec.push_back(std::move(mA_205));

            std::unique_ptr<Temperature> Temperature_307 = std::make_unique<Temperature>(307);
            std::unique_ptr<Pressure> Pressure_307 = std::make_unique<Pressure>(307);
            std::unique_ptr<mA> mA_307 = std::make_unique<mA>(307);
            sensor_vec.push_back(std::move(Temperature_307));
            sensor_vec.push_back(std::move(Pressure_307));
            sensor_vec.push_back(std::move(mA_307));

            for (const auto& a : sensor_vec) a->read();

        }
};

SensorVector::SensorVector()
{
}

SensorVector::~SensorVector()
{
}
