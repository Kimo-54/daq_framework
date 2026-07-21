#pragma once

#include "../Infrastructure/ThreadSafeQueue/ThreadSafeQueue.hpp"
#include "../Tasks/Sensors/Sensor.hpp"
#include "../Tasks/Sensors/Temperature.hpp"
#include "../Tasks/Sensors/Pressure.hpp"
#include "../Tasks/Sensors/mA.hpp"


class SensorQueue
{
    private:
        /* data */
    public:
        SensorQueue(/* args */);
        ~SensorQueue();
        void MainExTask()
        {
            ThreadSafeQueue<std::unique_ptr<Sensor>> sensor_q;

            std::unique_ptr<Temperature> Temperature_1 = std::make_unique<Temperature>(1);
            std::unique_ptr<Pressure> Pressure_1 = std::make_unique<Pressure>(1);
            std::unique_ptr<mA> mA_1 = std::make_unique<mA>(1);
            sensor_q.push(std::move(Temperature_1));
            sensor_q.push(std::move(Pressure_1));
            sensor_q.push(std::move(mA_1));

            std::unique_ptr<Temperature> Temperature_2 = std::make_unique<Temperature>(2);
            std::unique_ptr<Pressure> Pressure_2 = std::make_unique<Pressure>(2);
            std::unique_ptr<mA> mA_2 = std::make_unique<mA>(2);
            sensor_q.push(std::move(Temperature_2));
            sensor_q.push(std::move(Pressure_2));
            sensor_q.push(std::move(mA_2));

            std::unique_ptr<Temperature> Temperature_3 = std::make_unique<Temperature>(3);
            std::unique_ptr<Pressure> Pressure_3 = std::make_unique<Pressure>(3);
            std::unique_ptr<mA> mA_3 = std::make_unique<mA>(3);
            sensor_q.push(std::move(Temperature_3));
            sensor_q.push(std::move(Pressure_3));
            sensor_q.push(std::move(mA_3));

            std::unique_ptr<Sensor> sensor;
            while (sensor_q.try_pop(sensor))
            {
                sensor->read();
            }
        }
};

SensorQueue::SensorQueue()
{
}

SensorQueue::~SensorQueue()
{
}

