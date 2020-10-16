#include <iostream>

#include <string>
#include <vector>
#include <stack> // ayyy DFS-Stack ver whats up

#include <unordered_map>
#include <unordered_set>

#include <algorithm> // std::reverse

std::unordered_map <char, std::vector<char>> graph;
std::vector<char> empty;

int DFS (std::string restrict1, std::string restrict2){
    
    std::unordered_set <char> trvl;
    std::stack <char> DFS_Stack;
    
    trvl.insert('A');
    DFS_Stack.push('A');
    
    char node;
    std::string denyAccess;
    
    std::vector <char> neighs;
    
    while (DFS_Stack.size() != 0){
        
        node = DFS_Stack.top();
        DFS_Stack.pop();
        
        if (node == 'B') {
            return 0;
        }
        
        neighs = graph.at(node);
        
        for (char i : neighs){
            
            denyAccess = node;
            denyAccess.append(std::string(1, i));

            //std::cout << denyAccess << " \n";
            
            if ( (denyAccess == restrict1) or (denyAccess == restrict2) ){
                //std::cout << "restricted\n";
                continue;
            }
            
            if (trvl.find(i) == trvl.end()){
                trvl.insert(i);
                DFS_Stack.push(i);
            }
            
        }
        
        
    }
    
    std::cout << restrict1 << '\n';
    return 1;
}


int main(){
    
    std::vector <std::string> roads;
    
    std::string input;
    char node1, node2;
    
    while (true) {
        
        std::cin >> input;
        
        if (input == "**"){
            break;
        }
        
        node1 = input[0];
        node2 = input[1];

        roads.push_back(input);
        
        if (graph.find(node1) == graph.end()){
            graph.insert({node1, empty});
        }
        if (graph.find(node2) == graph.end()){
            graph.insert({node2, empty});
        }
        
        graph.at(node1).push_back(node2);
        graph.at(node2).push_back(node1);
        
    }
    
    int dcRoads = 0;
    
    for (std::string i : roads){
        
        std::string reversed = i;
        std::reverse (reversed.begin(), reversed.end());
        
        //std::cout << reversed << " " << i << '\n';
        dcRoads += DFS(i, reversed);
        
    }
    
    std::cout << "There are " << dcRoads << " disconnecting roads." << '\n';
    
}