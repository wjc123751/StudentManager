#include "student.h"
#include <iostream>

void Student::print() const {
    std::cout << "学号：" << id
              << "  姓名：" << name
              << "  成绩：" << score << std::endl;
}