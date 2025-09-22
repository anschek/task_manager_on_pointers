#include <iostream>
#include "../include/task.h"
int n = 5;
int m = 20;

void f1() {
    std::cout << "f1() has started\n";
    for (int i = 0, j = m; i < n; ++i, j+=n)
        std::cout << j << ' ';
    std::cout << "\nf1() has finished\n";
}

void f2() {
    std::cout << "f2() has started\n";
    for (int i = 0, j = 1; i < n; ++i, j*=2)
        std::cout << j << ' ';
    std::cout << "\nf2() has finished\n";
}

void f3() {
    std::cout << "f3() has started\n";
    std::cout << "f3() has finished\n";
}

int main() {
    Task tasks[3] = {
        {f1, Priority::LOW},
        {f2, Priority::HIGH},
        {f3, Priority::MEDIUM}
    };

    for (int i=0; i <4; ++i)
        for (auto task : tasks)
            add_task(task);
    execute_tasks_by_priority();

    std::cout << '\n';

    for (int i=0; i <2; ++i)
        for (auto task : tasks)
            add_task(task);
    execute_tasks_by_priority();

    return 0;
}