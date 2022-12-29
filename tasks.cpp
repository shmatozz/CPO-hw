#include "tasks.h"
#include "functions.h"

// work 1
void task1_1() {
    int number;
    std::cin >> number;
    std::cout << factorial(number) << std::endl;
}

void task1_2() {
    std::cout << "ax^2 + bx + c = 0" << std::endl;
    std::cout << "Input a, b, c" << std::endl;
    double a, b, c;
    std::cin >> a >> b >> c;
    double* x = square_x(a, b, c);
    if (x == nullptr) std::cout << "D < 0\nno x's";
    else std::cout << "x1 = " << x[0] << "\nx2 = " << x[1] << std::endl;
}

void task1_3() {
    int n = 100;
    simple_numbers(n);
}

void task1_4() {
    int n;
    std::cin >> n;
    std::cout << to_binary(n) << std::endl;
}

void task1_5() {
    double a, q, e;
    std::cin >> a >> q >> e;
    std::cout << geom_seq(a, q, e) << std::endl;
}

void task1_6() {
    char symbol;
    std::cin >> symbol;
    if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)) std::cout << "Symbol is a letter!" << std::endl;
    else std::cout << "Symbol is NOT a letter" << std::endl;
}

// --------------------------------
// work 2

void task2_1() {
    int* n = new int;
    std::cin >> *n;
    int* arr = new int[*n];
    fillArrayKB(*n, arr);
    printArray(*n, arr);

    bubbleSort(*n, arr);
    printArray(*n, arr);

    delete n;
    delete[] arr;
}

void task2_2() {

}

void task2_3() {

}
