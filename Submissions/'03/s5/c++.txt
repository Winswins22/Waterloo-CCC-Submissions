#include <iostream>

#include <vector>
#include <queue> // priority queue
#include <unordered_map>
#include <utility> // std::pair

#include <climits> // INT_MAX + INT_MIN

#include <algorithm> // std::min

// node : neighs {node, roadWeight}
std::unordered_map <int, std::vector < std::pair <int, int> > > graph;

// node : maximum weight that can be used to get here
std::unordered_map <int, int> bestWeight;

void dijkstra(){
    
    // pair : (maximumWeight, node)
    std::priority_queue < std::pair <int, int> > priority;
    priority.push(std::make_pair(INT_MAX, 1)); // starting node. "You can assume that you are starting in city 1."
    
    // first == weight. second == node.
    std::pair <int, int> weightNodePair;
    std::vector < std::pair <int, int> > neighs;
    
    int rWeight, calc;
    
    while (not priority.empty()){
        
        weightNodePair = priority.top();
        priority.pop();
        //std::cout << "Dijkstra: (" << weightNodePair.first << ", " << weightNodePair.second << ")\n";
        
        //check if invalid
        if (weightNodePair.first < bestWeight.at(weightNodePair.second)){
            //std::cout << "Invalid. Weight got rekt by " << bestWeight.at(weightNodePair.second);
            continue;
        }
        
        neighs = graph.at(weightNodePair.second);
        
        for (std::pair <int, int> i : neighs){
            //std::cout << "Looping at neighbour " << i.first << ' ';
            
            rWeight = i.second;
            calc = std::min (rWeight, weightNodePair.first);
            
            if (bestWeight.at(i.first) < calc){
                //std::cout << "New best weight: " << bestWeight.at(i.first) << " -> " << calc << " ";
                
                //std::cout << "New pair: (" << calc << ", " << i.first << ")\n";

                bestWeight.at(i.first) = calc;
                priority.push(std::make_pair(calc, i.first));
            }
            
        }
    }
    
}

int main(){
    
    int cities, roads, destinations;
    std::cin >> cities >> roads >> destinations;
    
    //get connections/roads ------------------------
    int city1, city2, roadMaxWeight;
    
    std::vector < std::pair <int, int> > emptyVector;
    
    for (int r = 1; r != roads + 1; r ++){
        std::cin >> city1 >> city2 >> roadMaxWeight;
        
        //check if keys exist, then push_back(node)
        if (graph.find(city1) == graph.end()){
            graph[city1] = emptyVector;
        }
        if (graph.find(city2) == graph.end()){
            graph[city2] = emptyVector;
        }
        
        graph.at(city1).push_back(std::make_pair(city2, roadMaxWeight));
        graph.at(city2).push_back(std::make_pair(city1, roadMaxWeight));
    }

    /*
    // Debug: Echoing graph

    std::cout << "\nDebug: Echoing graph\n";

    for (std::pair <int, std::vector< std::pair <int, int> > > i : graph){

        std::cout << "(" << i.first << ", {";

        for (std::pair <int, int> x : i.second){
            std::cout << "(" << x.first << ", " << x.second << "), ";
        }

        std::cout << "end})\n";
    }

    std::cout << '\n';
    */

    //----------------------------------------------
    
    //get destination citites ----------------------
    int input;
    std::vector <int> destinationCities;
    
    for (int city = 0; city != destinations; city ++){
        std::cin >> input;
        destinationCities.push_back(input);
    }
    //----------------------------------------------
    
    //initialize maxWeight
    for (int c = 1; c != cities + 1; c ++){
        bestWeight[c] = 0;
    }

    //Debug
    //std::cout << roadWeights[1] << roadWeights[2];
    
    dijkstra();
    
    //output ans
    int weight = INT_MAX;
    
    for (int i : destinationCities){
        weight = std::min(weight, bestWeight.at(i));
    }
    
    std::cout << weight << '\n';
}