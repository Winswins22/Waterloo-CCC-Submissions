#include <iostream>
#include <vector>

int main(){

    int rows, cols, choices;
    std::cin >> rows >> cols >> choices;

    // 2 states: Black, Gold
    // boolean : False, True
    // false : Black, true : Gold

    // 0,    1,    2
    // Gold, Gold, Black
    std::vector <std::vector<bool>> currentColor;

    // currentColor[0][1] = not currentColor[0][1];

    std::vector<bool> oneRow;

    for (int i = 0 ; i < cols; i ++){
        oneRow.push_back(false);
    }

    for (int i = 0; i < rows; i ++){
        currentColor.push_back(oneRow);
    }

    char rowOrCol;
    int position;

    for (int i = 0; i < choices; i ++){
        std::cin >> rowOrCol >> position;

        // Note:
        // We are subtracting 1 from position as a list counts up differently compared to a problem statement.
        // Problem: 1, 2, 3, 4
        // List: 0, 1, 2, 3
        // So, we subtract 1 from position to convert their counting system over to the list's counting system
        position = position - 1;

        if (rowOrCol == 'R'){

            for (int j = 0; j < cols; j ++){
                currentColor[position][j] = not currentColor[position][j];
            }

        }
        else{

            for (int j = 0; j < rows; j ++){
                currentColor[j][position] = not currentColor[j][position];
            }

        }

        
    }

    int goldTiles = 0;

    for (int row = 0; row < rows; row ++){
        for (int col = 0; col < cols; col ++){

            if (currentColor[row][col] == true){
                goldTiles = goldTiles + 1;
            }

        }
    }

    std::cout << goldTiles << '\n';

}