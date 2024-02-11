#include "calculator.h"
#include <cmath>

double Calculator::squareRoot(double number) {
    return sqrt(number);
}

double Calculator::naturalLog(double number) {
    return log(number);
}

int Calculator::power(int base, int exponent) {
    return static_cast<int>(pow(base, exponent));
}

int Calculator::factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
