//
// Created by anschek on 21.09.2025.
//

#include "../include/task.h"
#include <iostream>

size_t g_task_count = 0;
size_t g_task_capacity = 1;
std::unique_ptr<Task[]> g_tasks = std::make_unique<Task[]>(g_task_capacity);

void log_size() {
    std::cout << "count, capacity: " << g_task_count << ' ' << g_task_capacity << '\n';
}

void add_task(const Task &task) {
    if (g_task_count == g_task_capacity) {
        // выделение увеличенного участка памяти
        g_task_capacity *= 2;
        std::unique_ptr<Task[]> new_arr = std::make_unique<Task[]>(g_task_capacity);

        // перемещение count элементов с указателя g_tasks на новый адрес
        std::ranges::move(g_tasks.get(), g_tasks.get() + g_task_count, new_arr.get());

        g_tasks = std::move(new_arr); //возвращение владения
    }
    g_tasks[g_task_count++] = task; // добавление новой задачи, изменение счетчика
    log_size();
}

void execute_tasks_in_order() {
    for (size_t i = 0; i < g_task_count; ++i)
        g_tasks[i].func();
}

void sort_tasks_by_priority() {
    for (int i = 0; i < g_task_count; ++i) {
        bool flag = true;
        for (int j = 0; j < g_task_count - (i + 1); ++j) {
            if (g_tasks[j].priority < g_tasks[j + 1].priority) {
                flag = false;
                std::swap(g_tasks[j], g_tasks[j + 1]);
            }
        }
        if (flag) {
            break;
        }
    }
}

void execute_tasks_by_priority() {
    sort_tasks_by_priority();
    for (size_t i = 0; i < g_task_count; ++i)
        g_tasks[i].func();
    g_task_count = 0;
    log_size();
}