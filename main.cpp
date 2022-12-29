#include "functions.h"
#include "tasks.h"

int main() {
    double task_number;
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
    }

    return 0;
}
