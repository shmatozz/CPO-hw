#include "functions.h"

long long factorial(int i) {
    if (i < 0) return -1;
    else if (i == 0) return 1;
    else return i * factorial(i - 1);
}

double* square_x(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    if (d < 0) {
        double *x = nullptr;
        return x;
    } else if (d == 0) {
        auto* x = new double[1];
        x[0] = (-b) / (2 * a);
        return x;
    } else {
        auto* x = new double[2];
        x[0] = (-b + sqrt(d)) / (2 * a);
        x[1] = (-b - sqrt(d)) / (2 * a);
        return x;
    }
}

void simple_numbers(int n) {
    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) std::cout << i << std::endl;
    }
}

std::string to_binary(int n) {
    std::string ans;
    while (n > 0) {
        if (n % 2 == 0) ans.insert(ans.begin(), '0');
        else ans.insert(ans.begin(), '1');
        n /= 2;
    }
    return ans;
}

double geom_seq(double a, double q, double e) {
    double ans = 0;
    int step = 0;
    while (a * pow(q, step) > e) {
        ans += a * pow(q, step);
        step += 2;
    }
    return ans;
}

void bubbleSort(int n, int* arr) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void bubbleSort(int n, double* arr) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void bubbleSort(int n, short* arr) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <>
void bubbleSortTemp<char>(int n, char* arr) {
    for (int i = 0; i < n; ++i) {
        if (!((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))) {
            arr[i] = 123;
            printArray(n, arr);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (std::tolower(arr[i]) > std::tolower(arr[j])) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))) {
            arr[i] = 32;
            printArray(n, arr);
        }
    }
}

bool isPalindrome(std::string str) {
    auto start = str.begin();
    auto end = str.end() - 1;
    while (start != end) {
        if (*start != *end) return false;
        start += 1;
        end -= 1;
    }
    return true;
}