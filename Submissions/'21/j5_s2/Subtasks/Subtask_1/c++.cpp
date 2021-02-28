#include <iostream>

int main(){

    int rows, cols, choices;
    std::cin >> rows >> cols >> choices;

    // 2 states: Black, Gold
    // boolean : False, True
    // false : Black, true : Gold
    bool currentColor = false;

    for (int i = 0; i < choices; i ++){
        currentColor = not currentColor;
    }

    if (currentColor == false){
        // 0 tiles golden
        std::cout << 0 << '\n';
    }
    else{
        // current color == true == gold
        std::cout << 1 << '\n';
    }

}