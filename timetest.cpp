#include "func.cpp"
#include <chrono>
#include <cmath>

template<typename Func>
double measureTime(Func f, size_t iterations) {
    auto start = chrono::high_resolution_clock::now(); 

    for (size_t i = 0; i < iterations; i++) {
        f(); 
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start; 
    return duration.count() / iterations; 
}

double testrand(size_t iterations , int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size); // Генерация случайного числа
        b.random(size); // Генерация второго случайного числа
    }, iterations);
}


double testsum(size_t iterations , int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size); // Генерация случайного числа
        b.random(size); // Генерация второго случайного числа
        BigInt c = a + b; // Операция сложения
    }, iterations);
}


double testdiff(size_t iterations, int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size); // Генерация случайного числа
        b.random(size); // Генерация второго случайного числа
        BigInt c = a - b; // Операция сложения
    }, iterations);
}

double testmul(size_t iterations, int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size); // Генерация случайного числа
        b.random(size); // Генерация второго случайного числа
        BigInt c = a * b; // Операция сложения
    }, iterations);
}

double testdiv(size_t iterations, int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size); // Генерация случайного числа
        b.random(size); // Генерация второго случайного числа
        BigInt c = a / b; // Операция сложения
    }, iterations);
}



int main() {
    size_t iterations = 10000; 

    double avgRandTime = testrand(iterations, 32);
    double avgAddTime = testsum(iterations, 32);
    double avgSubTime = testdiff(iterations, 32);
    double avgMulTime = testmul(iterations, 32);
    double avgDivTime = testdiv(iterations, 32);

    cout << "Average time for random generation: " << avgRandTime * 1 << " seconds\n";
    cout << "Average time for addition: " << (avgAddTime - avgRandTime) * 1 << " seconds\n";
    cout << "Average time for subtraction: " << (avgSubTime - avgRandTime) * 1  << " seconds\n";
    cout << "Average time for multiplication: " << (avgMulTime - avgRandTime) * 1 << " seconds\n";
    cout << "Average time for division: " << (avgDivTime - avgRandTime) * 1 << " seconds\n";

    return 0;
}