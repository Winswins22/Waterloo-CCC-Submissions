// #include <extra_debugging_prompts>

#include <iostream>
#include <vector>
#include <deque>
#include <set>

std::vector <int> moveRow {1, 2, 2, 1, -1, -2, -2, -1};
std::vector <int> moveCol {2, 1, -1, -2, -2, -1, 1, 2};

std::deque <std::vector<int>> empty;

bool inGrid(std::vector<int> coords){
    
  int row = coords[0];
  int col = coords[1];

  if ((1 <= row) and (row <= 8) and ((1 <= col) and (col <= 8))){
      return true;
  }
  return false;
    
}

int BFS(std::vector<int> start, std::vector<int> endCoords){
    
    int currentDistanceFromStart = 0;
    
    //init trvl
    std::set <std::vector<int>> trvl;
    trvl.insert(start);
    
    std::deque <std::vector<int>> currentQueue;
    std::deque <std::vector<int>> nextQueue {start};
    
    std::vector<int> currentNode;
    
    std::vector<int> getConnections;
    
    while (nextQueue.size() != 0){
        
        currentQueue = nextQueue;
        nextQueue = empty;
    
        while (currentQueue.size() != 0){
            
            currentNode = currentQueue.front();
            currentQueue.pop_front();

            //std::cout << "New loop. Current node == " << currentNode[0] << " " << currentNode[1] << '\n';

            if (currentNode == endCoords){
                return currentDistanceFromStart;
            }
            
            for (int move = 0; move != 8; move ++){
                getConnections = currentNode;
                
                getConnections[0] += moveRow[move];
                getConnections[1] += moveCol[move];

                //std::cout<< getConnections[0] << " " << getConnections[1] << ' ';
                
                if (inGrid(getConnections)){
                  if (trvl.find(getConnections) == trvl.end()){
                      //std::cout << "inserted";
                      trvl.insert(getConnections);
                      nextQueue.push_back(getConnections);
                  }
                  
                }
                //std::cout<< '\n';
            }
          
        }
        currentDistanceFromStart += 1; 
    
    }
}

int main(){
    
    int startRow, startCol;
    int endRow, endCol;
    
    std::cin >> startRow >> startCol;
    std::cin >> endRow >> endCol;
    
    std::vector <int> start {startRow, startCol};
    std::vector <int> end {endRow, endCol};
    
    std::cout << BFS(start, end) << '\n';
    
}