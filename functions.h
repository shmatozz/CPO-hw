#ifndef CPO_HW_FUNCTIONS_H
#define CPO_HW_FUNCTIONS_H

#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <random>
#include <vector>
#include <sstream>
#include <algorithm>
#include "classes.h"

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

bool isPalindrome(std::string str);

template <typename T>
void printVector(std::vector<T> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';
    }
    std::cout << std::endl;
}

std::vector<std::string> stringToVector(const std::string& str);
std::vector<int> fillIntVector();

#endif //CPO_HW_FUNCTIONS_H
