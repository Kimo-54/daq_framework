#pragma once

#include <thread>
#include <atomic>
#include <chrono>

#include "../Sensors/Sensor.hpp"

class Task
{
    private:
        int _dt {10};
        Sensor* _sensor;
        std::thread _thread;
        std::atomic<bool> _running {false};

    protected:
        void to_run()
            {
                if (!_sensor) //guard against nullptr constructor
                {
                    return; 
                }
                auto next = std::chrono::steady_clock::now();
                const auto period = std::chrono::milliseconds(_dt);
                while(_running)
                {
                    _sensor -> read();
                    next += period;
                    std::this_thread::sleep_until(next);
                }
            }
        void join()
            {
                if (_thread.joinable())
                {
                    _thread.join();
                }
            }
    public:
    
        Task() : _sensor(nullptr) {} //to be able to inherit from Task
        Task (Sensor *sensor, int dt) : _dt(dt), _sensor(sensor) {}
        ~Task()
            {
                stop();
            }
        void run()
            {
                if (_thread.joinable()) 
                {    
                    return;
                }
                    _running = true;
                _thread = std::thread(&Task::to_run, this);
            }
        void stop()
            {
                _running = false;
                if (_thread.joinable())
                {
                    _thread.join();
                }
            }
            
        Task(const Task&) = delete;
        Task& operator=(const Task&) = delete;
};