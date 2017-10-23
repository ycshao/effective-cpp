//
// Created by Yuecheng Shao on 10/2/17.
//

#include "RandomType.h"
#include <iostream>

RandomType::RandomType() {
    std::cout << "RandomType::RandomType()\n";
}

RandomType::~RandomType() {
    std::cout << "RandomType::~RandomType()\n";
}

void RandomType::swap(RandomType other) {
    std::cout << "RandomType::swap()\n";
}

void RandomType::normalize() {
    std::cout << "RandomType::normalize()\n";
}

RandomType RandomType::size() const {
    return RandomType();
}
