#include "tasks.h"
#include "functions.h"

// work 1
void task1_1() {
    int number;
    std::cout << "Input number:";
    std::cin >> number;
    std::cout << "Factorial = " << factorial(number) << std::endl;
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
    std::cout << "Simple numbers from 1 to " << n << std::endl;
    simple_numbers(n);
}

void task1_4() {
    int n;
    std::cout << "Input number:";
    std::cin >> n;
    std::cout << "binary = " << to_binary(n) << std::endl;
}

void task1_5() {
    double a, q, e;
    std::cin >> a >> q >> e;
    std::cout << geom_seq(a, q, e) << std::endl;
}

void task1_6() {
    char symbol;
    std::cout << "Input symbol:";
    std::cin >> symbol;
    if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)) std::cout << "Symbol is a letter!" << std::endl;
    else std::cout << "Symbol is NOT a letter" << std::endl;
}

// --------------------------------
// work 2

void task2_1() {
    int* n = new int;
    std::cout << "Input length of array:";
    std::cin >> *n;
    int* arr = new int[*n];
    std::cout << "Fill array:";
    fillArrayKB(*n, arr);
    std::cout << "Initial array: ";
    printArray(*n, arr);

    bubbleSort(*n, arr);
    std::cout << "Sorted array: ";
    printArray(*n, arr);

    delete n;
    delete[] arr;
}

void task2_2() {
    int* n = new int;
    std::cout << "Input length of array:";
    std::cin >> *n;
    std::string type;
    std::cout << "Input type of array:";
    std::cin >> type;
    if (type == "int") {
        auto * arr = new int[*n];
        fill_sort(*n, arr);
    } else if (type == "double") {
        auto * arr = new double[*n];
        fill_sort(*n, arr);
    } else if (type == "short") {
        auto *arr = new short[*n];
        fill_sort(*n, arr);
    } else {
        std::cout << "Unknown type" << std::endl;
        return;
    }
    delete n;
}

void task2_3() {
    int* n = new int;
    std::cout << "Input length of array:";
    std::cin >> *n;
    std::string type;
    std::cout << "Input type of array:";
    std::cin >> type;
    if (type == "int") {
        auto * arr = new int[*n];
        fill_sort(*n, arr);
    } else if (type == "double") {
        auto * arr = new double[*n];
        fill_sort(*n, arr);
    } else if (type == "short") {
        auto *arr = new short[*n];
        fill_sort(*n, arr);
    } else if (type == "char") {
        auto *arr = new char[*n];
        fill_sort(*n, arr);
    } else {
        std::cout << "Unknown type" << std::endl;
        return;
    }
    delete n;
}

// --------------------------------
// work 3

void task3_1() {
    DynArray arr(10);
    arr.append(1.0);
    for (int i = 0; i < 15; ++i) {
        arr.append(i + 0.0);
    }
    for (int i = 0; i < arr.cur_length; ++i) {
        std::cout << arr.get(i) << ' ';
    }
    std::cout << std::endl;
}

void task3_2() {
    MyStack stack;
    stack.push(1);
    std::cout << stack.peak() << std::endl;

    for (int i = 0; i < 10; ++i) {
        stack.push(i + 2);
    }
    stack.print();
    std::cout << stack.pop() << std::endl;
    std::cout << stack.peak() << std::endl;
    stack.print();

    std::cout << stack.capacity() << std::endl;
    std::cout << stack.cur_size() << std::endl;
}

// --------------------------------
// work 4

void task4_1() {
    Vec3D a(1, 2, 1);
    Vec3D b(2, 2, 1);
    Vec3D c = a * b;
    a.print();
    b.print();
    std::cout << "Scalar multiply (a * b) = ";
    c.print();
    Vec3D d = a & b;
    std::cout << "Vector multiply (a & b) = ";
    d.print();
}

void task4_2() {
    DynArray arr(10);
    arr.append(1.0);
    for (int i = 0; i < 15; ++i) {
        arr.append(i);
    }
    std::cout << "Initial DynArray: ";
    arr.print();
    DynArray arr2;
    arr2 = arr;
    std::cout << "Operator= copy of DynArray: ";
    arr2.print();
    DynArray arr3 = arr;
    std::cout << "Copy ctor copy of DynArray: ";
    arr3.print();

    std::cout << "Current amount of \"alive\" elements = " << arr.cur_len() << std::endl;

    std::cout << "\nTesting [] operator:" << std::endl;
    std::cout << "Array[0] = " << arr[0] << std::endl;
    arr[0] = 10;
    arr.print();

    std::cout << "\nTesting + operator:" << std::endl;
    DynArray arr4 = arr + arr2;
    arr4.print();

    std::cout << "\nTesting >> operator:" << std::endl;
    arr >> 2;
    arr.print();

    std::cout << "\nTesting << operator:" << std::endl;
    arr << 2;
    arr.print();

}
