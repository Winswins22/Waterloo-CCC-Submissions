#include <iostream>

#include <vector>
#include <queue> //priority queue
#include <unordered_map>

#include <algorithm> //std::min
#include <utility> //std::pair

#include <climits> // INT_MAX

#include <functional> // std::greater

// #Format:
// # {page : shortestDistance} (unreachableDistance == INT_MAX)
std::unordered_map <int, int> dist;

// node : neighs
std::unordered_map <int, std::vector <int> > graph;

void dijkstra (){
    
    // from stack_overflow import *
    // make_pair(weight, node)
    // smallest distance pairs activate first
    std::priority_queue <std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > priority;
    
    std::pair <int, int> startingPair {1, 1};
    priority.push(startingPair);
    
    dist.at(1) = 1;
    
    std::pair <int, int> weightNodePair;
    std::vector <int> neighs;
    
    while (not priority.empty()){
        
        weightNodePair = priority.top();
        priority.pop();
        
        //unoptimal
        if (weightNodePair.first > dist.at(weightNodePair.second)){
            continue;
        }
        
        //make optimal
        //dist.at(weightNodePair.second) = weightNodePair.first;
        
        neighs = graph.at(weightNodePair.second);
        
        for (int i : neighs){
            
            if (weightNodePair.first + 1 < dist.at(i)){
                priority.push(std::make_pair(weightNodePair.first + 1, i));
                dist.at(i) = weightNodePair.first + 1;
            }
            
        }
        
    }
    
}

int main(){
    
    int totalPages;
    std::cin >> totalPages;
    
    int numConnections;
    int aConnection;
    std::vector <int> connections;
    
    std::vector <int> endingPages;
    
    for (int page = 1; page != totalPages + 1; page ++){
        
        std::cin >> numConnections;
        
        for (int i = 0; i != numConnections; i ++){
            std::cin >> aConnection;
            connections.push_back(aConnection);
        }
        
        if (numConnections == 0){
            endingPages.push_back(page);
        }
        
        graph[page] = connections;
        dist[page] = INT_MAX;
        connections.clear();
        
    }
    
    dijkstra();
    
    //check if all have been reached
    bool allReachable = true;
    
    for (std::pair <int, int> i : dist){
        if (i.second == INT_MAX){
            allReachable = false;
            break;
        }
    }
    
    if (allReachable){
        std::cout << "Y\n";
    }
    else{
        std::cout << "N\n";
    }
    
    //get minimum to end
    int minDist = INT_MAX;
    
    for (int page : endingPages){
        minDist = std::min(minDist, dist.at(page));
    }
    
    std::cout << minDist << '\n';
    
}