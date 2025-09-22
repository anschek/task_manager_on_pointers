//
// Created by anschek on 21.09.2025.
//

#ifndef TASK_MANAGER_ON_POINTERS_TASK_H
#define TASK_MANAGER_ON_POINTERS_TASK_H

#include <memory>

enum class Priority { LOW, MEDIUM, HIGH };
struct Task {
    void (*func)();
    Priority priority;
};

extern std::unique_ptr<Task[]> g_tasks;
extern size_t g_task_count;

void add_task(const Task& task);
void execute_tasks_by_priority();
#endif //TASK_MANAGER_ON_POINTERS_TASK_H
