//
// Created by Yuecheng Shao on 10/2/17.
//

#ifndef EFFECTIVE_CPP_NASTYWIDGET_H
#define EFFECTIVE_CPP_NASTYWIDGET_H


#include "Widget.h"

class NastyWidget : public Widget {
public:
    NastyWidget();

    virtual ~NastyWidget();

    size_t size() const;

    void normalize();
};


#endif //EFFECTIVE_CPP_NASTYWIDGET_H
