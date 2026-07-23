#pragma once

#include <memory>
#include <vector>     // std::vector     // std::unique_ptr, std::make_unique
#include <variant>    // std::variant, std::visit

class Sensor {
public:
    Sensor (int id) : id_(id){}
    virtual ~Sensor() = default;      // virtual dtor so delete works right
    virtual void read() = 0;   // virtual is the key

    int id() const { return id_; }

protected:
    int id_;
};