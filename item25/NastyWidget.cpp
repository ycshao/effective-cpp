//
// Created by Yuecheng Shao on 10/2/17.
//

#include "NastyWidget.h"
#include <iostream>

NastyWidget::NastyWidget() {
    std::cout << "NastyWidget::NastyWidget()\n";
}

NastyWidget::~NastyWidget() {
    std::cout << "NastyWidget::~NastyWidget()\n";
}

void NastyWidget::normalize() {
    std::cout << "NastyWidget::normalize()\n";
}

size_t NastyWidget::size() const {
    std::cout << "NastyWidget::size()\n";
    return Widget::size();
}
