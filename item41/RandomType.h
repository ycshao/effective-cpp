//
// Created by Yuecheng Shao on 10/2/17.
//

#ifndef EFFECTIVE_CPP_RANDOMTYPE_H
#define EFFECTIVE_CPP_RANDOMTYPE_H

#include "Widget.h"
#include <string>
#include <iostream>

class RandomType {
public:
    RandomType();

    virtual ~RandomType();

    RandomType size() const;
    void normalize();
    void swap(RandomType other);
};



#endif //EFFECTIVE_CPP_RANDOMTYPE_H
