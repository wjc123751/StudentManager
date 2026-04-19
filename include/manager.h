#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include "student.h"

class StudentManager {
private:
    std::vector<Student> students;  // STL核心：vector容器

public:
    // 添加学生
    void add(const Student& s);     // 常量:只读，不修改 引用:避免复制开销

    // 按学号删除
    bool removeById(const std::string& id);

    // 按学号查找
    Student* findById(const std::string& id);

    // 按成绩降序排序
    void sortByScoreDesc();

    // 显示所有
    void showAll() const;

    // 统计平均分
    double averageScore() const;
};

#endif