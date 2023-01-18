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
    DynArray<double> arr;
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
    DynArray<double> arr;
    arr.append(1.0);
    for (int i = 0; i < 15; ++i) {
        arr.append(i);
    }
    std::cout << "Initial DynArray: ";
    arr.print();
    DynArray<double> arr2;
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

// --------------------------------
// work 5

void task5_1() {
    std::cout << "The task is to refactor project to many files" << std::endl;
}

void task5_2() {
    Mat2D<int> matrix, matrix2;
    matrix.fill();
    matrix.print();
    matrix2.fill();
    matrix2.print();

    std::cout << "\nTesting (+) of matrix:" << std::endl;
    Mat2D matrix3 = matrix + matrix2;
    matrix3.print();

    std::cout << "\nTesting (*) of matrix:" << std::endl;
    Mat2D matrix4 = matrix * matrix2;
    matrix4.print();

    std::cout << "\nTesting indexation of matrix:" << std::endl;
    std::cout << "element (0,0) of matrix1 = " << matrix(0, 0) << std::endl;

    std::cout << "\nTesting transposition of matrix:" << std::endl;
    std::cout << "Before:" << std::endl;
    matrix.print();

    matrix.trans();

    std::cout << "After:" << std::endl;
    matrix.print();

    std::cout << "\nTesting determinant of matrix: " << std::endl;
    std::cout << matrix.determinant() << std::endl;

}

// --------------------------------
// work 6

void task6_1() {
    std::cout << "class DynArray was templated, now it can work with any* type\n" << std::endl;

    DynArray<int> int_arr;
    for (int i = 0; i < 10; ++i) { int_arr.append(i + 1); }
    DynArray<char> char_arr;
    for (int i = 0; i < 10; ++i) { char_arr.append((char)(i + 65)); }
    int_arr.print();
    char_arr.print();
}

void task6_2() {
    std::cout << "class DynArray was rewritten, now it implemented using std::vector<T>\n" << std::endl;

    DynArray<int> int_arr;
    for (int i = 0; i < 10; ++i) { int_arr.append(i + 1); }
    DynArray<char> char_arr;
    for (int i = 0; i < 10; ++i) { char_arr.append((char)(i + 65)); }
    int_arr.print();
    char_arr.print();
}

void task6_3() {
    MyQueue<int> q;
    std::cout << q.first() << std::endl;
    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }
    q.print();
    std::cout << "Pop element: " << q.pop() << std::endl;
    q.print();

    std::cout << "First element: " << q.first() << std::endl;
    std::cout << "Last element: " << q.last() << std::endl;
}

void task6_4() {
    std::cout << "class Mat2D was templated and rewritten, now it implemented using std::vector<T>\n" << std::endl;

    Mat2D<char> char_matrix;
    Mat2D<float> double_matrix;
    double_matrix.fill();
    double_matrix(0, 0) = 1.1;

    double_matrix.print();
    double_matrix.trans();
    double_matrix.print();

    double_matrix.print();
}

// --------------------------------
// work 7

void task7_1() {
    std::string a;
    std::cout << "Input string:" << std::endl;
    std::cin >> a;
    bool ans = isPalindrome(a);
    if (ans) std::cout << "String is palindrome" << std::endl;
    else std::cout << "String is NOT palindrome" << std::endl;
}

void task7_2() {
    std::string str;
    _flushall();       // очистка всех буферов
    getline(std::cin, str);
    std::vector<std::string> words = stringToVector(str);
    printVector(words);

    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {return a.length() < b.length();});

    printVector(words);
}

// --------------------------------
// work 8

void task8_1() {
    std::vector<int> vec = fillIntVector();
    std::cout << "Initial vector: ";
    printVector(vec);
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    auto i = vec.begin();
    while (i != vec.end()) {
        if (*i == 0) {
            vec.erase(i);
            continue;
        }
        i += 1;
    }

    vec.shrink_to_fit();
    std::cout << "\nModified vector: ";
    printVector(vec);
    std::cout << "Current capacity: " << vec.capacity() << std::endl;
}

void task8_2() {

}