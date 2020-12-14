#include <iostream>
#include <cmath>

int main() {
    
    int originalNumerator, originalDenominator;
    int whole, numerator, denominator;
    
    std::cin >> originalNumerator >> originalDenominator;
    
    numerator = originalNumerator % originalDenominator;
    denominator = originalDenominator;
    
    whole = (originalNumerator - numerator) / originalDenominator;
    
    for (int i = originalDenominator; i != 0; i--){
        
        if (numerator % i == 0 && denominator % i == 0){
            numerator /= i;
            denominator /= i;
        }
        
    }
    
    if (whole != 0){
        std::cout << whole << " ";
    }
    
    if (numerator != 0){
        std::cout << numerator << "/" << denominator;
    }
    
    
}