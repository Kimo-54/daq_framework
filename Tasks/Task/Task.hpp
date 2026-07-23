#pragma once

#include <thread>
#include <atomic>
#include <chrono>

class Task
{
    private:
        std::thread _thread;

    protected:
        Task() = default;

        virtual void to_run() = 0; //the one thing derived classes have to provide, loops until _running is false

        std::atomic<bool> _running {false};

    public:
        virtual ~Task()
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
            //_thread = std::thread([this] { to_run(); });
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

        void join()
        {
            if (_thread.joinable())
            {
                _thread.join();
            }
        }
        
        bool is_running()
        {
            return _running;
        }

        Task(const Task&) = delete;
        Task& operator=(const Task&) = delete;
};