
#include "Tasks/Task/Task.hpp"
#include "Tasks/Task/ExTask.hpp"
#include "Tasks/Sensors/Sensor.hpp"
#include "Tasks/Sensors/Temperature.hpp"
#include "Tasks/Sensors/Pressure.hpp"
#include "Tasks/Sensors/mA.hpp"


int main()
{
    // SensorQueue q1;
    // SensorVector v1;
    // std::unique_ptr<ExTask> Task1 = std::make_unique<ExTask>(q1,v1);
    // Task1 -> runEx();
    // Task1 -> run_queue();
    // Task1 -> run_vector();

    Temperature temp1(25);
    auto Task2 = std::make_unique<Task> (&temp1, 15);
    Task2 ->run();
    
    Pressure press1(37);
    auto Task3 = std::make_unique<Task> (&press1, 20);
    Task3 ->run();
    
    mA mA1(98);
    auto Task4 = std::make_unique<Task> (&mA1, 35);
    Task4 ->run();

    while (true) std::this_thread::sleep_for(std::chrono::seconds(1));
}