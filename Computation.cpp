#include <iostream>
#include "Computation.hpp"

int Computation::add(const int &a, const int &b) const {
    return a + b;
}

int Computation::subtract(const int &a, const int &b) const {
    return a - b;
}

int Computation::addCoverage(const int &a, const int &b) const {
    int answer = -1;

    if(a > 0 && b > 0) {
        answer = a + b;
    }
    else {
        answer = 0;
    }
    return answer;
}

int Computation::subtractCoverage(const int &a, const int &b) const {
    int answer = -1;
    
    if(a > 0 && b > 0) {
        answer = a - b;
    }
    else {
        answer = 0;
    }
    return answer;
}