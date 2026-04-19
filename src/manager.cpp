#include "manager.h"
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

void StudentManager::add(const Student& s) {
    students.push_back(s);      // 添加到vector末尾，效率高
}

bool StudentManager::removeById(const string& id) {
    // 删除后不改变原顺序，效率较低
    // for (auto it = students.begin(); it != students.end(); ++it) {
    //     if (it->id == id) {
    //         students.erase(it); // 删掉it指向的元素，vector会自动把后面的元素往前挪
    //         return true;
    //     }
    // }
    // 删除后改变原顺序，效率较高
    for(auto& s : students) {
        if (s.id == id) {
            s = students.back(); // 用最后一个元素覆盖当前元素
            students.pop_back(); // 删除最后一个元素
            return true;
        }
    }
    return false;
}

Student* StudentManager::findById(const string& id) {
    for (auto& s : students) {      // auto自动判断类型，&引用避免复制开销
        if (s.id == id)
            return &s;
    }
    return nullptr;
}

// 排序用的比较函数
static bool compareScore(const Student& a, const Student& b) {
    return a.score > b.score;
}

void StudentManager::sortByScoreDesc() {
    sort(students.begin(), students.end(), compareScore);
    // 也可以用lambda表达式, 没有函数名，直接写在需要的地方，用 [] 开头
    // sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
    //     return a.score > b.score;
    // });
}

void StudentManager::showAll() const {  // const成员函数不能修改成员变量
    for (const auto& s : students) {
        s.print();
    }
}

double StudentManager::averageScore() const {
    if (students.empty()) return 0.0;
    int sum = accumulate(students.begin(), students.end(), 0,   //  C++ STL 专门用来遍历容器并计算总和的算法
        [](int s, const Student& a) { return s + a.score; });
    return static_cast<double>(sum) / students.size();          // static_cast<double> 显式类型转换
}