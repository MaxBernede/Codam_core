#pragma once

#include <iostream>
#include <string>

#include "Data.hpp"

class Serializer {
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
private:
    Serializer();
};

