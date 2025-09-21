//
// Created by anschek on 21.09.2025.
//

#include "../include/task.h"
#include <iostream>

size_t g_task_count = 0;
std::unique_ptr<Task[]> g_tasks = std::make_unique<Task[]>(g_task_count);

void add_task(Task task) {
    // выделение увеличенного участка памяти
    std::unique_ptr<Task[]> new_arr = std::make_unique<Task[]>(g_task_count + 1);

    // перемещение count элементов с указателя g_tasks на новый адрес
    std::ranges::move(g_tasks.get(), g_tasks.get() + g_task_count, new_arr.get());

    new_arr[g_task_count++] = task; // добавление новой задачи, изменение счетчика
    g_tasks = std::move(new_arr); //возвращение владения
}

void execute_tasks_in_order() {
    for (size_t i = 0; i < g_task_count; ++i)
        g_tasks[i].func();
}