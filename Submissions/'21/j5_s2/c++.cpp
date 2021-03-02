#include <iostream>
#include <vector>

int main(){

    int rows, cols, choices;
    std::cin >> rows >> cols >> choices;

    // 0,    1,    2
    // Gold, Gold, Black
    // false == no paint, true == paint
    std::vector<bool> paintRow;
    std::vector<bool> paintCol;

    // Initialize paintRow and paintCol with black
    for (int i = 0; i < rows; i ++){
        paintRow.push_back(false);
    }
    for (int i = 0; i < cols; i ++){
        paintCol.push_back(false);
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

        // If the artist paints over a certain row/col twice, it cancels out.
        // Use "not" to simulate the cancelling out
        if (rowOrCol == 'R'){
            paintRow[position] = not paintRow[position];
        }
        else{
            paintCol[position] = not paintCol[position];
        }
        
    }

    int goldTiles = 0;
    int rows_with_black = 0;
    int rows_with_gold = 0;

    // check if the artist over a row
    // Add up the gold tiles gained from painting over a row, while tracking
    // how many rows with black and rows with gold there are
    for (int i = 0; i < rows; i ++){
        if (paintRow[i] == true){
            goldTiles = goldTiles + cols;
            rows_with_gold = rows_with_gold + 1;
        }
        else{
            rows_with_black = rows_with_black + 1;
        }
    }

    // check if the artist over a col
    // use this formula to calculate how many new gold tiles are created when the artist paints over a col:
    // new_gold_tiles = rows_with_black - rows_with_gold
    int new_gold_tiles;

    for (int i = 0; i < cols; i ++){
        if (paintCol[i] == true){
            new_gold_tiles = rows_with_black - rows_with_gold;
            goldTiles = goldTiles + new_gold_tiles;
        }
    }

    std::cout << goldTiles << '\n';

}