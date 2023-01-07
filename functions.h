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
        this->cur_length = 0;
    }
    DynArray(const DynArray& second) {
        this->arr = new double[second.size];
        this->size = second.size;
        this->cur_length = 0;
        for (int i = 0; i < second.cur_length; ++i) {
            this->append(second.arr[i]);
        }
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

    [[nodiscard]] int cur_len() const {
        return cur_length;
    }

    void print() const {
        for (int i = 0; i < cur_length; ++i) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }

    DynArray& operator=(const DynArray& second) {
        this->cur_length = 0;
        for (int i = 0; i < second.cur_length; ++i) {
            this->append(second.arr[i]);
        }
        this->size = second.size;
        return *this;
    }
    double& operator[](int i) const {
        return arr[i];
    }
    DynArray operator+(const DynArray& second) const {
        DynArray temp(this->cur_length + second.cur_length);
        for (int i = 0; i < this->cur_length; ++i) {
            temp.append(this->arr[i]);
        }
        for (int i = 0; i < this->cur_length; ++i) {
            temp.append(second.arr[i]);
        }
        return temp;
    }
    DynArray& operator>>(int k) {
        k = k % cur_length;
        for (int i = 0; i < k; ++i) {
            double last = this->arr[cur_length - 1];
            for (int j = cur_length - 2; j >= 0; j--) {
                this->arr[j + 1] = this->arr[j];
            }

            this->arr[0] = last;
        }
        return *this;
    }
    DynArray& operator<<(int k) {
        k = k % cur_length;
        for (int i = 0; i < k; ++i) {
            double last = this->arr[0];
            for (int j = 1; j < cur_length; j++) {
                this->arr[j - 1] = this->arr[j];
            }
            this->arr[cur_length - 1] = last;
        }
        return *this;
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

class Vec3D {
public:
    double x, y, z;
    Vec3D() : x(0.0), y(0.0), z(0.0) {}
    Vec3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    Vec3D operator*(Vec3D second) const {
        Vec3D new_vec;
        new_vec.x = this->x * second.x;
        new_vec.y = this->y * second.y;
        new_vec.z = this->z * second.z;
        return new_vec;
    }

    Vec3D operator&(Vec3D second) const {
        Vec3D new_vec;
        new_vec.x = this->y * second.z - this->z * second.y;
        new_vec.y = this->z * second.x - this->x * second.z;
        new_vec.z = this->x * second.y - this->y * second.x;
        return new_vec;
    }

    void print() const {
        std::cout << '(' << this->x << ", " << this->y << ", " << this->z << ')' << std::endl;
    }
};

class Mat2D {
public:
    Mat2D(int n_, int m_) : n(n_), m(m_) {
        matrix = new int*[n_];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[m_];
        }
        std::cout << "~created matrix " << n << 'x' << m << std::endl;
    }
    Mat2D() {
        std::cout << "Input dim of matrix NxM:" << std::endl;
        std::cin >> n >> m;
        matrix = new int*[n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new int[m];
        }
        std::cout << "~created matrix " << n << 'x' << m << std::endl;
    }
    ~Mat2D() {
        for (int i = 0; i < n; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    int** matrix = new int*[1];
    int n{}, m{};

    void fill() const {
        std::cout << "Input matrix" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> matrix[i][j];
            }
        }
    }
    void print() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { std::cout << this->matrix[i][j] << ' '; }
            std::cout << std::endl;
        }
    }

    Mat2D operator+(const Mat2D& second) const {
        if (this->n != second.n || this->m != second.m) {
            std::cout << "Dimension error (+), first matrix returned" << std::endl;
            return *this;
        }
        Mat2D temp(this->n, this->m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                temp.matrix[i][j] = this->matrix[i][j] + second.matrix[i][j];
            }
        }
        return temp;
    }
    Mat2D operator*(const Mat2D& second) const {
        if (this->m != second.n) {
            std::cout << "Dimension error (*), first matrix returned" << std::endl;
            return *this;
        }
        Mat2D temp(this->n, second.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < second.m; ++j) {
                temp.matrix[i][j] = 0;
                for (int k = 0; k < this->m; ++k) {
                    temp.matrix[i][j] += this->matrix[i][k] * second.matrix[k][j];
                }
            }
        }
        return temp;
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
