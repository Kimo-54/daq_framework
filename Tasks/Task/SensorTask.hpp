#pragma once

#include <thread>
#include <atomic>
#include <chrono>

#include "Task.hpp"
#include "../Sensors/Sensor.hpp"

class SensorTask : public Task
{
    private:
        Sensor* _sensor;
        int _dt {10};

        protected:
            void to_run() override
            {
                auto next = std::chrono::steady_clock::now();
                const auto period = std::chrono::milliseconds(_dt);
                while (_running)
                {
                    _sensor -> read();
                    next += period;
                    std::this_thread::sleep_until(next);
                }
            }
        
        public:
            SensorTask() = delete;
            SensorTask (Sensor* sensor, int dt) : _sensor(sensor), _dt(dt) {}
            ~SensorTask() override
            {
                stop(); // stop before _sensor becomes dangling
            }
};