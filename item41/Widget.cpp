//
// Created by Yuecheng Shao on 10/2/17.
//

#include "Widget.h"
#include <iostream>

Widget::Widget() {
    std::cout << "Widget::Widget()\n";
}

Widget::~Widget() {
    std::cout << "Widget::~Widget()\n";
}

void Widget::normalize() {
    std::cout << "Widget::normalize()\n";
}

void Widget::swap(Widget &other) {
    std::cout << "Widget::swap()\n";
}

size_t Widget::size() const {
    std::cout << "Widget::size()\n";
    return 10;
}
