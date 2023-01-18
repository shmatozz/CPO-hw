#ifndef CPO_HW_CLASSES_H
#define CPO_HW_CLASSES_H
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <random>
#include <vector>

template <class T>
class DynArray {
public:
    explicit DynArray() {
        arr.clear();
        cur_length = 0;
    }
    DynArray(const DynArray& second) {
        arr.clear();
        this->cur_length = 0;
        for (int i = 0; i < second.cur_length; ++i) {
            this->append(second.arr[i]);
        }
    }
    ~DynArray() = default;

    // T *arr = new T[1];
    std::vector<T> arr;
    int cur_length = 0;

    void append(T val) {
        arr.push_back(val);
        cur_length++;
    }

    [[nodiscard]] T get(int index) const {
        return arr[index];
    }

    [[nodiscard]] int cur_len() const {
        return arr.size();
    }

    void print() const {
        for (int i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << ' ';
        }
        std::cout << std::endl;
    }

    DynArray& operator=(const DynArray& second) {
        this->cur_length = 0;
        for (int i = 0; i < second.cur_length; ++i) {
            this->append(second.arr[i]);
        }
        return *this;
    }
    T& operator[](int i) {
        return arr[i];
    }
    DynArray operator+(const DynArray& second) const {
        DynArray temp;
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

template <class T>
class MyQueue {
public:
    MyQueue() {
        queue.clear();
        cur_length = 0;
    }
    ~MyQueue() = default;

    std::vector<T> queue;
    int cur_length = 0;

    void push(T val) {
        queue.push_back(val);
        cur_length++;
    }
    T pop() {
        T ans = queue[0];
        operator<<(1);
        cur_length--;
        return ans;
    }
    T first() {
        if (cur_length > 0) return queue[0];
        std::cout << "Queue is empty!\n-1 returned" << std::endl;
        return -1;
    }
    T last() {
        if (cur_length > 0 ) return queue[cur_length - 1];
        std::cout << "Queue is empty!\n-1 returned" << std::endl;
        return -1;
    }
    void print() {
        for (auto i = 0; i < cur_length; i++) {
            std::cout << queue[i] << ' ';
        }
        std::cout << std::endl;
    }

    MyQueue<T> operator<<(int k) {
        k = k % cur_length;
        for (int i = 0; i < k; ++i) {
            double last = this->queue[0];
            for (int j = 1; j < cur_length; j++) {
                this->queue[j - 1] = this->queue[j];
            }
            this->queue[cur_length - 1] = last;
        }
        return *this;
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

template <class T>
class Mat2D {
public:
    Mat2D(int n_, int m_) {
        this->n = n_;
        this->m = m_;
        matrix.reserve(n);
        for (int i = 0; i < m; ++i) {
            matrix[i].reserve(m);
        }
        std::cout << "~matrix created " << n << 'x' << m << std::endl;
    }
    Mat2D() {
        std::cout << "Input dim of matrix NxM:" << std::endl;
        std::cin >> n >> m;
        matrix.reserve(n);
        for (int i = 0; i < m; ++i) {
            matrix[i].reserve(m);
        }
        std::cout << "~matrix created " << n << 'x' << m << std::endl;
    }
    Mat2D(const Mat2D& matrix) {
        this->n = matrix.n;
        this->m = matrix.m;
        this->matrix.reserve(n);
        for (int i = 0; i < this->n; ++i) {
            this->matrix[i].reserve(m);
            for (int j = 0; j < this->m; ++j) {
                this->matrix[i][j] = matrix.matrix[i][j];
            }
        }
        std::cout << "~matrix created " << n << 'x' << m << std::endl;
    }
    ~Mat2D() {
        std::cout << "~matrix deleted " << n << 'x' << m << std::endl;
    }

    std::vector<std::vector<T>> matrix;
    int n{}, m{};

    void fill() {
        std::cout << "Input matrix" << std::endl;
        T a;
        for (int i = 0; i < n; ++i) {
            std::vector<T> temp;
            for (int j = 0; j < m; ++j) {
                std::cin >> a;
                temp.push_back(a);
            }
            matrix.push_back(temp);
        }
    }
    void print() const {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) { std::cout << this->matrix[i][j] << ' '; }
            std::cout << std::endl;
        }
    }
    void trans() {
        std::vector<std::vector<T>> temp;
        temp.resize(m);
        for (int i = 0; i < this->m; ++i) {
            temp[i].resize(n);
            for (int j = 0; j < this->n; ++j) {
                temp[i][j] = this->matrix[j][i];
            }
        }
        matrix = temp;
        std::swap(this->n, this->m);
    }
    [[nodiscard]] int determinant() const {
        if (this->n != this->m) {
            std::cout << "n != m, matrix is not squared" << std::endl;
            return 0;
        }

        return 1;
    }


    Mat2D operator+(const Mat2D& second) {
        if (this->n != second.n || this->m != second.m) {
            std::cout << "Dimension error (+), first matrix returned" << std::endl;
            return *this;
        }
        Mat2D<T> temp(this->n, this->m);
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
        Mat2D<T> temp(this->n, second.m);
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
    T& operator()(int i, int j)
    {
        return matrix[i][j];
    }

};


#endif //CPO_HW_CLASSES_H
