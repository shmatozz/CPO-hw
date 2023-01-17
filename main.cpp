#include "functions.h"
#include "tasks.h"

int main() {
    double task_number;
    std::cout << "Input task number:";
    std::cin >> task_number;

    if (task_number == 1.1) {
        task1_1();
    } else if (task_number == 1.2) {
        task1_2();
    } else if (task_number == 1.3) {
        task1_3();
    } else if (task_number == 1.4) {
        task1_4();
    } else if (task_number == 1.5) {
        task1_5();
    } else if (task_number == 1.6) {
        task1_6();
    } else if (task_number == 2.1) {
        task2_1();
    } else if (task_number == 2.2) {
        task2_2();
    } else if (task_number == 2.3) {
        task2_3();
    } else if (task_number == 3.1) {
        task3_1();
    } else if (task_number == 3.2) {
        task3_2();
    } else if (task_number == 4.1) {
        task4_1();
    } else if (task_number == 4.2) {
        task4_2();
    } else if (task_number == 5.1) {
        task5_1();
    } else if (task_number == 5.2) {
        task5_2();
    } else if (task_number == 6.1) {
        task6_1();
    } else if (task_number == 6.2) {
        task6_2();
    } else if (task_number == 6.3) {
        task6_3();
    } else if (task_number == 6.4) {
        task6_4();
    }

    return 0;
}
