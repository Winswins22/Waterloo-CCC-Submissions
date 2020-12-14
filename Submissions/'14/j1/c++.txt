#include <iostream>

int main(){
    
    int a, b, c;
    
    std::cin >> a >> b >> c;
    
    if (a == b and b == c and c == 60){
        std::cout << "Equilateral\n";
    }
    
    else if ((a == b or b == c or a == c) and a + b + c == 180){
        std::cout << "Isosceles\n";
    }
    
    else if (a + b + c == 180){
        std::cout << "Scalene\n";
    }
    
    else{
        std::cout << "Error\n";
    }
    
}