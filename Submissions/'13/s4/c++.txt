#include <iostream>

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

#include <string> //literally only used as return

std::unordered_map<int, std::vector<int>> shorterOnly;

//Example
// start = 1
// end = 3
// 1 : {2, 3}
// 2 and 3 are shorter than 1, therefore 1 is taller
std::unordered_map<int, std::vector<int>> tallerOnly;


std::string BFS (int start, int end){
    
    std::unordered_set<int> trvl ({start}); 
    std::unordered_set<int> startTrvl ({start}); 
    
    // Declare vars that will be used in both BFSs ---- //
    int node;
    
    std::queue <int> emptyQueue;
    std::queue <int> startQueue ({start});
    
    std::queue <int> searching;
    std::queue <int> nextSearch ({start});
    
    std::vector<int> neighs;
    
    // For copying over to the shorter search. Will have the exact same contents as trvl up until the shorter BFS
    std::queue <int> allSearchesSoFar ({start});
    
    
    // ------------------------------------------------ //
    
    // (Checks in tallerOnly)
    // Start the check to see if person is taller ----- //
    while (nextSearch.size() != 0){
        
        searching = nextSearch;
        nextSearch = emptyQueue;
        
        while (searching.size() != 0){
            
            node = searching.front();
            searching.pop();
            
            if (node == end){
                return "yes";
            }
            
            if (tallerOnly.find(node) == tallerOnly.end()){
                continue;
            }
            
            neighs = tallerOnly.at(node);
            
            for (int i : neighs){
                
                if (trvl.find(i) == trvl.end()){
                    trvl.insert(i);
                    allSearchesSoFar.push(i);
                    nextSearch.push(i);
                }
                
            }
            
        }
        
    }
    
    // ------------------------------------------------ //
    
    // (Checks in shorterOnly)
    // Start the check to see if person is shorter --- //
    
    searching = emptyQueue;
    nextSearch = startQueue;
    
    trvl = startTrvl;
    
    while (nextSearch.size() != 0){
        
        searching = nextSearch;
        nextSearch = emptyQueue;
        
        while (searching.size() != 0){
            
            node = searching.front();
            searching.pop();
            
            if (node == end){
                return "no";
            }
            
            if (shorterOnly.find(node) == shorterOnly.end()){
                continue;
            }
            
            neighs = shorterOnly.at(node);
            
            for (int i : neighs){
                
                if (trvl.find(i) == trvl.end()){
                    trvl.insert(i);
                    nextSearch.push(i);
                }
                
            }
            
        }
        
    }
    
    
    // ------------------------------------------------ //
    
    // Person's height is unknown if both searches have failed.
    return "unknown";
    
}

int main(){
    
    std::vector<int> empty;
    
    int people, comparisons;
    std::cin >> people >> comparisons;
    
    int start, end;
    int person1, person2;
    
    for (int i = 0; i != comparisons; i ++){
        
        std::cin >> person1 >> person2;
        
        //Check if keys exist
        if (shorterOnly.find(person2) == shorterOnly.end()){
            shorterOnly[person2] = empty;
        }
        
        if (tallerOnly.find(person1) == tallerOnly.end()){
            tallerOnly[person1] = empty;
        }
        
        shorterOnly.at(person2).push_back(person1);
        
        tallerOnly.at(person1).push_back(person2);
        
    }
    
    std::cin >> start >> end;
    
    std::cout << BFS(start, end) << '\n';
    
}