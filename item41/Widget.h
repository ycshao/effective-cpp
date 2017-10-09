//
// Created by Yuecheng Shao on 10/2/17.
//

#ifndef PROJECT_WIDGET_H
#define PROJECT_WIDGET_H

#include <cstdio>
#include <string>

class Widget {
public:
    Widget();
    virtual ~Widget();

    virtual size_t size() const;
    virtual void normalize();
    void swap(Widget& other);
};

#endif //PROJECT_WIDGET_H
