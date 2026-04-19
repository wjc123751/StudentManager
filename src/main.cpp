#include <iostream>
#include <windows.h>   // 必须加上这一行！
#include "student.h"
#include "manager.h"

using namespace std;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    StudentManager sm;

    // 添加测试数据
    sm.add({"1001", "张三", 92});
    sm.add({"1002", "李四", 85});
    sm.add({"1003", "王五", 96});

    cout << "===== 全部学生 =====" << endl;
    sm.showAll();

    cout << "\n===== 按成绩排序 =====" << endl;
    sm.sortByScoreDesc();
    sm.showAll();

    cout << "\n===== 查找学号1002 =====" << endl;
    auto p = sm.findById("1002");
    if (p) p->print();

    cout << "\n===== 删除学号1002 =====" << endl;
    sm.removeById("1002");
    sm.showAll();

    cout << "\n平均分: " << sm.averageScore() << endl;

    return 0;
}