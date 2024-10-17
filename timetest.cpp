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
        a.random(size, size); 
        b.random(size, size); 
    }, iterations);
}


double testsum(size_t iterations , int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size, size); 
        b.random(size, size); 
        BigInt c = a + b; 
    }, iterations);
}


double testdiff(size_t iterations, int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size, size); 
        b.random(size, size); 
        BigInt c = a - b; 
    }, iterations);
}

double testmul(size_t iterations, int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size, size); 
        b.random(size, size);
        BigInt c = a * b; 
    }, iterations);
}

double testdiv(size_t iterations, int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size, size); 
        b.random(1, size-1);
        BigInt c = a / b; 
    }, iterations);
}

double testrand1(size_t iterations , int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size,size); 
        b = 100;  
    }, iterations);
}

double testpow(size_t iterations, int size) {
    return measureTime([&]() {
        BigInt a, b;
        a.random(size,size); 
        b = 100; 
        BigInt c = a.pow(b); 
    }, iterations);
}


int main() {
    size_t iterations = 10000;
    int sizee = 32; 

    double avgRandTime = testrand(iterations, sizee);
    double avgRandTime1 = testrand1(iterations, sizee);
    double avgAddTime = testsum(iterations, sizee);
    double avgSubTime = testdiff(iterations, sizee);
    double avgMulTime = testmul(iterations, sizee);
    double avgDivTime = testdiv(iterations, sizee);
    //double avgPowTime = testpow(iterations - 9900, sizee);

    cout << "Average time for random generation: " << avgRandTime * 1 << " seconds\n";
    cout << "Average time for addition: " << (avgAddTime - avgRandTime) * 1 << " seconds\n";
    cout << "Average time for subtraction: " << (avgSubTime - avgRandTime) * 1  << " seconds\n";
    cout << "Average time for multiplication: " << (avgMulTime - avgRandTime) * 1 << " seconds\n";
    cout << "Average time for division: " << (avgDivTime - avgRandTime) * 1 << " seconds\n";
    //cout << "Average time for exp: " << (avgPowTime - avgRandTime1) * 1 << " seconds\n";

    return 0;
}