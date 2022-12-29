#ifndef CPO_HW_FUNCTIONS_H
#define CPO_HW_FUNCTIONS_H

#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <random>

class DynArray {
public:
    explicit DynArray(int size) {
        this->arr = new double[size];
        this->size = size;
        cur_length = 0;
    }
    explicit DynArray() {
        this->arr = new double[1];
        this->size = 1;
        cur_length = 0;
    }
    ~DynArray() {
        delete[] arr;
    }

    double *arr = new double[1];
    int size, cur_length;

    void append(double val) {
        if (cur_length == size) {
            auto *temp = new double[size * 2 + 1];
            for (int i = 0; i < cur_length; ++i) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            size = size * 2 + 1;
        }
        arr[cur_length] = val;
        cur_length++;
    }

    [[nodiscard]] double get(int index) const {
        return arr[index];
    }
};

class MyStack {
public:
    explicit MyStack(int size) {
        this->stack = new int[size];
        this->size = size;
        cur_length = 0;
    }
    explicit MyStack() {
        this->stack = new int[1];
        this->size = 1;
        cur_length = 0;
    }
    ~MyStack() {
        delete[] stack;
    }

    int *stack = new int[1];
    int size, cur_length;

    void push(int value) {
        if (cur_length == size) {
            auto *temp = new int[size * 2 + 1];
            for (int i = 0; i < cur_length; ++i) {
                temp[i] = stack[i];
            }
            delete[] stack;
            stack = temp;
            size = size * 2 + 1;
        }
        stack[cur_length] = value;
        cur_length++;
    }

    int pop() {
        cur_length--;
        return stack[cur_length];
    }

    [[nodiscard]] int peak() const {
        return stack[cur_length - 1];
    }

    [[nodiscard]] int capacity() const {
        return size;
    }

    [[nodiscard]] int cur_size() const {
        return cur_length;
    }

    void print() const {
        for (int i = 0; i < cur_length; ++i) {
            std::cout << stack[i] << ' ';
        }
        std::cout << std::endl;
    }
};

long long factorial(int i);

double* square_x(double a, double b, double c);

void simple_numbers(int n);

std::string to_binary(int n);

double geom_seq(double a, double q, double e);

void bubbleSort(int n, int* arr);
void bubbleSort(int n, double* arr);
void bubbleSort(int n, short* arr);

template <typename T>
void fillArray(int n, T* arr) {
    std::mt19937 mt_engine(
            std::chrono::system_clock::now().
                    time_since_epoch().count()
    );
    std::uniform_int_distribution<int> dist(-100, 100);
    for (int i = 0; i < n; i++) {
        arr[i] = dist(mt_engine);
    }

}

template <typename T>
void printArray(int n, T* arr) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void fillArrayKB(int n, T* arr) {
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}

template <typename T>
void bubbleSortTemp(int n, T* arr) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <>
void bubbleSortTemp<char>(int n, char* arr);

template <typename T>
void fill_sort(int n, T* arr) {
    std::cout << "Fill array:";
    fillArrayKB(n, arr);
    std::cout << "Initial array: ";
    printArray(n, arr);

    bubbleSortTemp(n, arr);
    std::cout << "Sorted array: ";
    printArray(n, arr);

    delete[] arr;
}

#endif //CPO_HW_FUNCTIONS_H
