#include <iostream>
#include <vector>

int main(){

    int rows, cols, choices;
    std::cin >> rows >> cols >> choices;

    // 2 states: Black, Gold
    // boolean : False, True
    // false : Black, true : Gold

    // 0,     1,     2
    // Gold,  Gold, Black
    std::vector<bool> currentColor;

    for (int i = 0 ; i < cols; i ++){
        currentColor.push_back(false);
    }

    char rowOrCol;
    int position;

    for (int i = 0; i < choices; i ++){
        std::cin >> rowOrCol >> position;

        if (rowOrCol == 'C'){
            currentColor[position-1] = not currentColor[position-1];
        }
        else{

            for (int j = 0; j < cols; j ++){
                currentColor[j] = not currentColor[j];
            }

        }
    }

    int goldTiles = 0;

    for (int i = 0; i < cols; i ++){
        if (currentColor[i] == true){
            goldTiles = goldTiles + 1;
        }
    }

    std::cout << goldTiles << '\n';

}