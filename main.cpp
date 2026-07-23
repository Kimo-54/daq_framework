#include "Tasks/Task/Task.hpp"
#include "Tasks/Task/SensorTask.hpp"
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
    auto Task2 = std::make_unique<SensorTask> (&temp1, 70);
    Task2 -> run();
    
    Pressure press1(37);
    auto Task3 = std::make_unique<SensorTask> (&press1, 80);
    Task3 -> run();
    
    mA mA1(98);
    auto Task4 = std::make_unique<SensorTask> (&mA1, 20);
    Task4 -> run();

    Temperature temp2(125);
    auto Task5 = std::make_unique<SensorTask> (&temp2, 10);
    Task5 -> run();
    
    Pressure press2(137);
    auto Task6 = std::make_unique<SensorTask> (&press2, 50);
    Task6 -> run();
    
    mA mA2(198);
    auto Task7 = std::make_unique<SensorTask> (&mA2, 60);
    Task7 -> run();
    
    while (true) std::this_thread::sleep_for(std::chrono::seconds(1));
}