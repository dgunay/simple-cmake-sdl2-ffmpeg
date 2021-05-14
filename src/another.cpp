#include "another.h"
#include <iostream>
#include <optional>

void another() {
    std::cout << "another thing!" << std::endl;
    std::optional<int> maybe = 5;
    std::cout << "found a " << maybe.value();
}