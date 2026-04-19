#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    std::string id;     // 学号
    std::string name;   // 姓名
    int score;          // 分数

    // 打印信息
    void print() const;
};

#endif