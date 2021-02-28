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
        position = position - 1;

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