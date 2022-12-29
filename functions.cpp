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

void bubbleSort(int arrLen, int* arr) {
    for (int i = 0; i < arrLen; i++) {
        for (int j = i + 1; j < arrLen; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void fillArray(int n, int* arr) {
    std::mt19937 mt_engine(
            std::chrono::system_clock::now().
                    time_since_epoch().count()
    );
    std::uniform_int_distribution<int> dist(-100, 100);
    for (int i = 0; i < n; i++) {
        arr[i] = dist(mt_engine);
    }

}

void printArray(int n, int* arr) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void fillArrayKB(int n, int* arr) {
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}