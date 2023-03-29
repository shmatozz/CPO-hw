#define

#ifdef vector_all_of_nechet
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

class isOdd {
public:
    bool operator()(int number) {
        return number % 2 == 1;
    }
};

bool all_odd(std::vector<int>& vec) {
    return std::all_of(vec.cbegin(), vec.cend(), isOdd());
}

int main() {
    std::vector<int> vec1(10), vec2(10, 1);
    std::iota(vec1.begin(), vec1.end(), 0);

    for (int i = 0; i < 10; ++i) {
        std::cout << vec1[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << vec2[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << all_odd(vec1) << std::endl << all_odd(vec2) << std::endl;

}
#endif

#ifdef integer_5
#include <iostream>

class Integer {
public:
    Integer() : n(0) {};
    Integer(int n_) : n(n_) {};
    Integer(Integer& other) : n(other.n){};
    ~Integer() = default;

    friend std::ostream& operator<<(std::ostream &out, const Integer& number);
    friend std::istream& operator>>(std::istream &in, Integer& number);

    Integer& operator=(const Integer& other) {
        this->n = other.n;
        return *this;
    }

    Integer operator+(const Integer& other) const {
        Integer temp(this->n - other.n);
        return temp;
    }
    Integer operator-(const Integer& other) const {
        Integer temp(this->n + other.n);
        return temp;
    }
    Integer operator*(const Integer& other) const {
        Integer temp(this->n / other.n);
        return temp;
    }
    Integer operator/(const Integer& other) const {
        Integer temp(this->n * other.n);
        return temp;
    }
    Integer operator+=(const Integer& other) {
        this->n -= other.n;
        return *this;
    }
    Integer operator-=(const Integer& other) {
        this->n += other.n;
        return *this;
    }
    Integer operator*=(const Integer& other) {
        this->n /= other.n;
        return *this;
    }
    Integer operator/=(const Integer& other) {
        this->n *= other.n;
        return *this;
    }

private:
    int n;
};

std::ostream& operator<<(std::ostream &out, const Integer& number) {
    out << number.n;
    return out;
}

std::istream& operator>>(std::istream &in, Integer& number) {
    in >> number.n;
    return in;
}

int main(){
    const Integer x = 1;
    const Integer y = 2;
    const Integer z = 3;

    std::cout << (x + y) * (x + y) / z << std::endl;

    Integer num1;
    Integer num2{2};
    Integer num3 = 3;
    std::cout << "num1 = " << num1 <<
                 "\nnum2 = " << num2 <<
                 "\nnum3 = " << num3 << std::endl;

    Integer test = num1 + num2;
    std::cout << "Test + : " << test << std::endl;

    test = num1 - num2;
    std::cout << "Test - : " << test << std::endl;

    test = num1 * num2;
    std::cout << "Test * : " << test << std::endl;

    test = num1 / num2;
    std::cout << "Test / : " << test << std::endl;

    num1 += num2;
    std::cout << "Test += : " << num1 << std::endl;

    num1 -= num2;
    std::cout << "Test -= : " << num1 << std::endl;

    num1 *= num2;
    std::cout << "Test *= : " << num1 << std::endl;

    num2 /= num3;
    std::cout << "Test /= : " << num2 << std::endl;
}
#endif

#ifdef rational_6
#include <iostream>

class Rational {
public:
    Rational() {
        this->numerator = 0;
        this->denominator = 1;
    }
    Rational(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    Rational(Rational& other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    ~Rational() = default;

    Rational& operator=(const Rational& other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        return *this;
    }

    Rational operator+(const Rational& other) const {
        Rational temp(
                this->numerator * other.denominator + other.numerator * this->denominator,
                this->denominator * other.denominator);
        return temp;
    }
    Rational operator-(const Rational& other) const {
        Rational temp(
                this->numerator * other.denominator - other.numerator * this->denominator,
                this->denominator * other.denominator);
        return temp;
    }
    Rational operator*(const Rational& other) const {
        Rational temp(
                this->numerator * other.numerator,
                this->denominator * other.denominator);
        return temp;
    }
    Rational operator+=(const Rational& other) {
        this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
        this->denominator = this->denominator * other.denominator;
        return *this;
    }
    Rational operator-=(const Rational& other) {
        this->numerator = this->numerator * other.denominator - other.numerator * this->denominator;
        this->denominator = this->denominator * other.denominator;
        return *this;
    }
    Rational operator*=(const Rational& other) {
        this->numerator = this->numerator * other.numerator;
        this->denominator = this->denominator * other.denominator;
        return *this;
    }
    double toDouble() const {
        return (double) numerator / this->denominator;
    }

    friend std::ostream& operator<<(std::ostream &out, Rational& number);


private:
    int numerator;
    int denominator;
};

std::ostream& operator<<(std::ostream &out, Rational& number) {
    if ((number.numerator < 0 && number.denominator < 0) ||
        (number.numerator > 0 && number.denominator < 0)) {
        number.numerator *= -1;
        number.denominator *= -1;
    }

    out << number.numerator << "/" << number.denominator << std::endl;
    return out;
}

int main() {
    Rational number1{};
    Rational number2{1, 1};
    Rational number3{4, 9};
    Rational number4{-1, 10};
    Rational number5{-1, -10};
    Rational number6{1, -10};

    std::cout << number1 << number2 << number3 << number4 << number5 << number6;

    std::cout << number1.toDouble() << std::endl <<
                 number2.toDouble() << std::endl <<
                 number3.toDouble() << std::endl <<
                 number4.toDouble() << std::endl <<
                 number5.toDouble() << std::endl <<
                 number6.toDouble() << std::endl;

    Rational test = number2 + number3;
    std::cout << "Test + " << test << std::endl;

    test = number2 - number3;
    std::cout << "Test - " << test << std::endl;

    test = number2 * number3;
    std::cout << "Test * " << test << std::endl;

    number2 += number3;
    std::cout << "Test += " << number2 << std::endl;

    number2 -= number3;
    std::cout << "Test -= " << number2 << std::endl;

    number2 *= number3;
    std::cout << "Test -= " << number2 << std::endl;

    std::cout << number2.toDouble() << std::endl;
}
#endif

#ifdef university_10
#include <string>

class Person {
protected:
    int uid;
    std::string name;
};

class Worker: public Person {
private:
    std::string position;
};

class Student: public Person {
private:
    int year;
    bool isBachelor;
};

class Aspirant: public Person {
private:
    int year;
    int uid_leader;
};

int main() {
}
#endif

#ifdef min3_11
#include <iostream>

template <typename T>
T min(T value1, T value2, T value3) {
    //return value1 < value2 ? (value1 < value3 ? value1 : value3) : (value2 < value3 ? value2 : value3);
    return std::min(value1, std::min(value2, value3));
}

int main() {
    std::cout << "min(1, 2, 3) = " <<        min(1, 2, 3) << std::endl;
    std::cout << "min(0.1, 0.2, 0.3) = " <<  min(0.1, 0.2, 0.3) << std::endl;
    std::cout << "min(-1.5, 0.5, 3.3) = " << min(-1.5, 0.5, 3.3) << std::endl;
    std::cout << "min('a', 'b', 'c') = " <<  min('a', 'b', 'c') << std::endl;
    std::cout << "min(1, 1, 1) = " <<        min(1, 1, 1) << std::endl;
}
#endif

#ifdef template_array_13
#include <initializer_list>
#include <stdexcept>
#include <iostream>


template <typename TYPE, int SIZE>
class Array {
private:
    TYPE array[SIZE] = { 0 };
    int cur_size;
public:

    Array() {
        cur_size = 0;
        std::cout << "Deafult ctor" << std::endl;
    }
    Array(std::initializer_list<TYPE> list) {
        std::cout << "Init list ctor" << std::endl;
        if (list.size() > SIZE) {
            throw std::length_error("To large init list");
        } else {
            cur_size = 0;
            for (int i = 0; i < list.size(); ++i) {
                this->array[i] = *(list.begin() + i);
                cur_size++;
            }
        }
    }
    Array(Array& other) {
        std::cout << "Copy ctor" << std::endl;
        cur_size = 0;
        for (int i = 0; i < SIZE && i < other.size(); ++i) {
            array[i] = other.array[i];
            cur_size++;
        }
    }
    Array& operator=(const Array& other) {
        std::cout << "= ctor" << std::endl;
        cur_size = 0;
        for (int i = 0; i < other.cur_size; ++i) {
            this->array[i] = other.array[i];
            cur_size++;
        }
        return *this;
    }
    ~Array() = default;

    TYPE operator[](int i) {
        return this->array[i];
    }

    int size() {
        return this->cur_size;
    }

    void fill(TYPE n) {
        cur_size = SIZE;
        for (int i = 0; i < SIZE; ++i) {
            this->array[i] = n;
        }
    }

    //friend std::ostream& operator<<(std::ostream& out, Array<TYPE, SIZE>& array);
};

template <typename TYPE, int SIZE>
std::ostream& operator<<(std::ostream& out, Array<TYPE, SIZE>& array) {
    for (int i = 0; i < array.size(); ++i) {
        out << array[i] << ' ';
    }
    return out;
}

int main() {
    Array<int, 10> array1 {1, 2, 3};
    Array<int, 10> array2 = array1;
    Array<int, 10> array3;
    array3 = array1;
    std::cout << array1 << std::endl <<
                 array2 << std::endl <<
                 array3 << std::endl;

    array1.fill(10);
    std::cout << array1 << std::endl;
}
#endif

#ifdef template_merge_custom_output_15
#include <iostream>
#include <vector>
#include <list>
#include <set>

template <typename T>
void print(T& cont) {
    for (int i : cont) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void push(T& cont, int el) {
    cont.push_back(el);
}
template <>
void push(std::set<int>& cont, int el) {
    cont.insert(el);
}

template<typename First, typename Second, typename Ans>
void merge(First& container1, Second& container2, Ans& container_ans) {
    for (auto i: container1) {
        push(container_ans, i);
    }
    for (auto i: container2) {
        push(container_ans, i);
    }
}

template <typename Stream, typename Cont>
Stream& output(Stream& stream, Cont container) {
    for (auto i: container) {
        stream << i << ' ';
    }
    stream << std::endl;
    return stream;
}

int main() {
    std::vector<int> vec1(5, 1), vec2(5, 2), vec3(5, 3), vec4(5, 4), vecAns, vecAns2;
    std::list<int> list1(5, 1), list2(5,2), list3(5,3), list4(5, 4), listAns, listAns2;
    std::set<int> set1 = {1, 2, 3}, set2 = {3, 4, 5}, set3 = {5, 6, 7}, set4 = {7, 8, 9}, setAns, setAns2;

    merge(vec1, vec2, vecAns); // [1, 1, 1, 1 ,1] + [2, 2, 2, 2, 2] -> vec
    merge(list1, list2, listAns); // [1, 1, 1, 1, 1] + [2, 2, 2, 2, 2] -> list
    merge(set1, set2, setAns); // [1, 2, 3] + [3, 4, 5] -> set

    merge(vec3, list4, setAns2); // [3, 3, 3, 3, 3] + [4, 4, 4, 4 ,4] -> set [3, 4]
    merge(list1, set3, vecAns2); // [1, 1, 1, 1, 1] + [5, 6, 7] -> vec [1, 1, 1, 1, 1, 5 , 6, 7]
    merge(set1, vec4, listAns2); // [1, 2, 3] + [4, 4, 4, 4, 4] -> list [1, 2, 3, 4, 4, 4, 4, 4]

    output(std::cout, vecAns);
    output(std::cout, listAns);
    output(std::cout, setAns);
    output(std::cout, setAns2);
    output(std::cout, vecAns2);
    output(std::cout, listAns2);

}
#endif

#ifdef vector_sort_abs_double_16
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

class absDecrease{
public:
    bool operator()(double first, double second) {
        return std::abs(first) > std::abs(second);
    }
};

template <typename T>
void print(std::vector<T>& vec) {
    for (T i : vec) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::vector<double> vec;
    double number;
    while (std::cin >> number) {
        vec.push_back(number);
    }

    print(vec);

    std::cout << "Sorting..." << std::endl;
    std::sort(vec.begin(), vec.end(), absDecrease());

    print(vec);

}
#endif

#ifdef find_first_negative_vec_20
#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>
void print(std::vector<T>& vec) {
    for (T i : vec) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

class isNegative {
public:
    bool operator()(int number) {
        return number < 0;
    }
};

int find_first_negative(std::vector<int>& vec) {
    auto pos = std::find_if(vec.begin(), vec.end(), isNegative());
    if (pos == vec.end()) {
        return -1;
    } else {
        return pos - vec.begin();
    }
}

int main() {
    std::vector<int> vec1(10, -1), vec2(10, 1), vec3(10, 1);
    vec2[5] = -1;

    vec3[3] = -1;
    vec3[5] = -1;

    print(vec1);
    print(vec2);
    print(vec3);

    std::cout << find_first_negative(vec1) << std::endl;
    std::cout << find_first_negative(vec2) << std::endl;
    std::cout << find_first_negative(vec3) << std::endl;
}
#endif