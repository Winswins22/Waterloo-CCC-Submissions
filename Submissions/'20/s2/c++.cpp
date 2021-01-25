#include <iostream>

#include <vector>
#include <unordered_set>
#include <stack>

#include <utility> // std::pair
#include <string> // return for dfs

#include <cmath> // floor, ceil, sqrt

int totalRow, totalCol;
std::vector< std::vector<int> > maze;

bool inBorders (int row, int col){
    
    if ((1 <= row) and (row <= totalRow) and (1 <= col) and (col <= totalCol)){
        return true;
    }
    return false;
    
}

std::vector< std::pair<int, int> > factor (int value){
    
    float check;
    
    std::vector< std::pair<int, int> > combs;
    std::pair<int, int> temp;
    
    for (int i = 1; i != ceil(sqrt(value) + 1); i ++){
        
        check = value / i;
        
        // check if (check, i) are valid factors
        if (floor(check) == ceil(check) and (i * check) == value){

            //Check if equal. If equal. push_back only once
            //Also check if in borders
            if (check == i){
                
                if (inBorders (check, check)){
                    temp.first = check;
                    temp.second = check;
                    
                    combs.push_back(temp);
                }
                
            }
            else {
                
                if (inBorders(check, i)){
                    temp.first = check;
                    temp.second = i;
                    
                    combs.push_back(temp);
                }
                
                if (inBorders(i, check)){
                    temp.first = i;
                    temp.second = check;
                    
                    combs.push_back(temp);
                }
                
            }
                
            
            
        }
        
    }
    
    
    return combs;
}

std::string DFS (){
    
    std::unordered_set<int> trvl;
    std::stack <int> DFS_Stack;
    
    int node;
    std::vector< std::pair<int, int> > neighs;
    
    trvl.insert(maze[0][0]);
    DFS_Stack.push(maze[0][0]);
    
    while (not DFS_Stack.empty()){
        
        node = DFS_Stack.top();
        DFS_Stack.pop();
        
        neighs = factor(node);
        
        for (std::pair <int, int> i : neighs){
            
            if (i.first == totalRow and i.second == totalCol){
                return "yes";
            }
            
            node = maze.at(i.first - 1).at(i.second - 1);
            
            if (trvl.find(node) == trvl.end()){
                trvl.insert(node);
                DFS_Stack.push(node);
            }
        }
        
    }
    
    return "no";
}

int main(){
    
    std::cin.sync_with_stdio(0);
    std::cin.tie(0);
    
    std::cin >> totalRow >> totalCol;
    
    int temp;
    std::vector<int> tempRow;
    std::vector<int> empty;
    
    for (int r = 0; r != totalRow; r ++){
        for (int c = 0; c != totalCol; c ++){
            std::cin >> temp;
            tempRow.push_back(temp);
        }
        maze.push_back(tempRow);
        tempRow = empty;
    }
    
    /*
    for (int r = 0; r != totalRow; r ++){
        for (int c = 0; c != totalCol; c ++){
            std::cout << maze[r][c] << " ";
        }
        std::cout << '\n';
    }
    */

    std::cout << DFS() << '\n';
}