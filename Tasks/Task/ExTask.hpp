#pragma once

#include <iostream>
#include <thread>

#include "Task.hpp"
#include "../../Configs/SensorQueue.hpp"
#include "../../Configs/SensorVector.hpp"

class ExTask : Task
{
    private:
        SensorQueue _q;
        SensorVector _v;
    public:
        ExTask();    
        ExTask(SensorQueue _q , SensorVector _v);
        ~ExTask();
        
        void runEx()
        {
            std::thread t1(&SensorVector::MainExTask,&_v);
            std::thread t2(&SensorQueue::MainExTask,&_q);
            t1.join();
            t2.join();
        };
        
        void run_queue()
        {
            std::thread t(&SensorQueue::MainExTask,&_q);
            t.join();
        };

        void run_vector()
        {
            std::thread t(&SensorVector::MainExTask,&_v);
            t.join();
        };
};

ExTask::ExTask()
{
}

ExTask::ExTask(SensorQueue,SensorVector)
{
}

ExTask::~ExTask()
{
}