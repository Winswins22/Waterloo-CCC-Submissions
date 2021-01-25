#include <iostream>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>

#include <utility> // std::pair

#include <algorithm> // sort
#include <functional> // std::greater, allows reversed sort

const std::vector<int> moveHor {-1, 1, 0, 0};
const std::vector<int> moveVert {0, 0, -1, 1};

int totalRow, totalCol;

std::vector < std::vector<char> > plan;
std::map < std::pair<int, int>, std::vector< std::pair<int, int> > > graph;

std::set < std::pair<int, int> > trvl;

bool inBorders (std::pair <int, int> coords){
    if ((0 <= coords.first) and (coords.first <= totalRow - 1) and (0 <= coords.second) and (coords.second <= totalCol - 1)){
        return true;
    }
    return false;
}

// what this function does:
// creates outbound connections from this node by:

// checking if the current coords is wall, return empty vector if yes
// checking the 4 tiles around currrents coords, adds to return vector if not wall
std::vector < std::pair<int, int> > searchFourDirections (std::pair <int, int> coords){
    
    std::vector < std::pair<int, int> > toReturn;
    char valueAtNode;
    
    //check current node
    if (inBorders(coords)){
        valueAtNode = plan.at(coords.first).at(coords.second);
        
        if (valueAtNode == 'I'){
            return toReturn;
        }
        
    }
    else{
        return toReturn;
    }
    
    //check surrounding nodes
    std::pair<int, int> newLocation;
    
    for (int direction = 0; direction != 4; direction ++){
        
        newLocation.first = coords.first + moveVert.at(direction);
        newLocation.second = coords.second + moveHor.at(direction);
        
        if (inBorders(newLocation)){
            valueAtNode = plan.at(newLocation.first).at(newLocation.second);
            
            if (valueAtNode == '.'){
                toReturn.push_back(newLocation);
            }
        }
        
    }
    
    return toReturn;
}

int BFS (std::pair <int, int> coords){
    //std::cout << "BFS: (" << coords.first << ", " << coords.second << ")\n";

    if (trvl.find(coords) != trvl.end()){
        //std::cout << "Returned: 0\n";
        return 0;
    }

    if (plan.at(coords.first).at(coords.second) == 'I'){
        return 0;
    }
    
    int tilesInRoom = 1;
    
    std::pair<int, int> node;
    std::vector < std::pair<int, int> > neighs;
    
    std::queue < std::pair<int, int> > searching;
    std::queue < std::pair<int, int> > nextSearch;
    nextSearch.push(coords);
    
    trvl.insert(coords);
    
    while (not nextSearch.empty()){
        
        searching = nextSearch;
        nextSearch = {};
        
        while (not searching.empty()){
            
            node = searching.front();
            searching.pop();
            
            neighs = graph.at(node);
            
            for (std::pair <int, int> i : neighs){
                
                if (trvl.find(i) == trvl.end()){
                    //std::cout << "(" << i.first << ", " << i.second << ") ";
                    trvl.insert(i);
                    nextSearch.push(i);
                    tilesInRoom ++;
                }
                
            }
            
        }
        
    }
    
    //std::cout << "Returned: " << tilesInRoom << '\n';
    return tilesInRoom;
}

int main(){
    
    int flooring;
    std::string row;
    std::vector <char> tempRow;
    
    std::cin >> flooring >> totalRow >> totalCol;
    
    //build plan
    for (int r = 0; r != totalRow; r ++){
        std::cin >> row;
        
        for (char c : row){
            tempRow.push_back(c);
        }
        
        plan.push_back(tempRow);
        tempRow.clear();
    }
    
    //build graph
    std::pair <int, int> tempRowColPair;
    std::vector < std::pair<int, int> > emptyValue;
    
    std::vector < std::pair<int, int> > neighs;
    
    for (int r = 0; r != totalRow; r ++){
        for (int c = 0; c != totalCol; c ++){
            
            tempRowColPair.first = r;
            tempRowColPair.second = c;
            
            neighs = searchFourDirections(tempRowColPair);
            
            //insert pairs and create new key
            graph[tempRowColPair] = emptyValue;
                        
            for (std::pair <int, int> i : neighs){
                graph.at(tempRowColPair).push_back(i);
            }
            
        }
    }
    
    //search for room sizes
    std::pair <int, int> tempCoords;
    std::vector <int> roomSizes;
    int result;
    
    for (int r = 0; r != totalRow; r ++){
        for (int c = 0; c != totalCol; c ++){
            
            tempCoords.first = r;
            tempCoords.second = c;
            
            result = BFS (tempCoords);
            
            if (result != 0){
                roomSizes.push_back(result);
            }
            
        }
    }
    
    //calculate output
    std::sort (roomSizes.begin(), roomSizes.end(), std::greater<int>());
    
    int roomsFloored = 0;
    int flooringAfter;
    
    for (int i : roomSizes){
        flooringAfter = flooring - i;
        
        if (flooringAfter < 0){
            break;
        }
        
        flooring = flooringAfter;
        roomsFloored ++;
        //std::cout << i << " ";
    }
    
    if (roomsFloored == 1){
        std::cout << "1 room, " << flooring << " square metre(s) left over\n";
    }
    else{
        std::cout << roomsFloored << " rooms, " << flooring << " square metre(s) left over\n";
    }

    /*
    //output graph for debugging\n
    std::cout << "\nOutputting graph for debugging\n";

    //std::map < std::pair<int, int>, std::vector< std::pair<int, int> > > graph;

    for (std::pair < std::pair<int, int>, std::vector< std::pair<int, int> > > keyValue : graph){
        //output key

        std::cout << "(" << keyValue.first.first << ", " << keyValue.first.second << ") ";

        //output value
        for (std::pair<int, int> i : keyValue.second){
          std::cout << "(" << i.first << ", " << i.first << ") ";
        }
        std::cout << '\n';
    }
    */
}