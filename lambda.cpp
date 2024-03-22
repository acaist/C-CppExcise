#include <iostream>

int globalVar = 42;

int main() {
    static int staticVar = 24;

    // Pass variables as arguments
    auto lambda1 = [](int localVar, int global) {
        std::cout << "Local variable: " << localVar << std::endl;
        std::cout << "Global variable: " << global << std::endl;
    };

    lambda1(staticVar, globalVar);

    // Capture variables explicitly
    auto lambda2 = [&staticVar, &globalVar]() {
        std::cout << "Static variable: " << staticVar << std::endl;
        std::cout << "Global variable: " << globalVar << std::endl;
    };

    lambda2();

    return 0;
}
