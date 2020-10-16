// Input translation:
/*
first line:
    hullPoints, islands, routes

the next int(routes) lines:
    island1, island2, timeNeeded, hullDamage

the last line:
    startingIsland, endIsland
*/

#include <iostream>

#include <vector>
#include <queue>
#include <utility>
#include <array>
#include <unordered_map>

#include <functional>
#include <climits>

typedef std::array <int, 3> triple; // substitutes triple -> std::array <int, 3> on compilation
typedef std::pair <int, int> intPair;

int hullPoints, islands, routes;
int start, end;

// Format:
// node : {{timeNeeded, healthNeeded, islandToGoTo}, ...}
std::unordered_map <int, std::vector <triple> > graph;

// node : currentGoodPair
// 'good' b/c this will be updated if either the time OR health is better than the current pair.
// hopefullly this prevent cycles and optimize a bit better
std::unordered_map <int, intPair> goodPair;

// actually checks if better or equal
// also updates goodPair if better is found
bool isBetter (intPair currentPair, intPair aGoodPair, int island){
    
    // validity check
    if (currentPair.second >= hullPoints){
        return false;
    }
    
    
    // exception for last node - max out time only!
    if (island == end){

        if (currentPair.first < aGoodPair.first){
            goodPair.at(island) = currentPair;
            return true;
        }
    
        return false;
        
    }
    
    // compare for equal
    if (currentPair == aGoodPair){
        return true;
    }
    
    // compare for better
    if (currentPair.first < aGoodPair.first or currentPair.second < aGoodPair.second){
        goodPair.at(island) = currentPair;
        return true;
    }
    
    return false;
}

void dijkstra (){
    
    //std::cout << "Numbers in time, health, island format.\n";
    std::priority_queue <triple, std::vector<triple>, std::greater<triple> > priority;
    
    triple init {0, 0, start};
    priority.push(init);
    
    triple node;
    triple nextNode;
    std::vector <triple> neighs;
    
    while (not priority.empty()){
        
        node = priority.top();
        priority.pop();
        //std::cout << "Dijkstra: (" << node.at(0) << ", " << node.at(1) << ", " << node.at(2) << ")\n";
        
        if (not isBetter(std::make_pair(node.at(0), node.at(1)), goodPair.at(node.at(2)), node.at(2))){
            //std::cout << "Not optimal, beaten by (" << goodPair.at(node.at(2)).first << ", " << goodPair.at(node.at(2)).second << ")\n";
            continue;
        }
        
        neighs = graph.at(node.at(2));
        
        for (triple i : neighs){
            
            nextNode.at(0) = node.at(0) + i.at(0);
            nextNode.at(1) = node.at(1) + i.at(1);
            nextNode.at(2) = i.at(2);
            //std::cout << "(" << nextNode.at(0) << ", " << nextNode.at(1) << ", " << nextNode.at(2) << ")   ";
            
            if (isBetter(std::make_pair(nextNode.at(0), nextNode.at(1)), goodPair.at(nextNode.at(2)), nextNode.at(2))){
                //std::cout << "Added\n";
                priority.push(nextNode);
            }
            
        }
        
        
    }
    
}

int main(){
    
    std::cin >> hullPoints >> islands >> routes;
    
    
    int island1, island2, timeNeeded, hullDamage;
    std::vector <triple> emptyVector;
    triple arr;
    
    for (int r = 1; r != routes + 1; r ++){
        
        std::cin >> island1 >> island2 >> timeNeeded >> hullDamage;
        
        //check keys exist
        if (graph.find(island1) == graph.end()){
            graph[island1] = emptyVector;
        }
        if (graph.find(island2) == graph.end()){
            graph[island2] = emptyVector;
        }
        
        arr.at(0) = timeNeeded;
        arr.at(1) = hullDamage;
        arr.at(2) = island2;
        
        graph.at(island1).push_back(arr);
        
        arr.at(2) = island1;
        
        graph.at(island2).push_back(arr);
        
    }
    
    // init goodPair
    intPair defaultVal = {INT_MAX, INT_MAX}; // infinite time and damage taken
    
    for (int i = 1; i != islands + 1; i ++){
        goodPair[i] = defaultVal;
    }
    
    //get start/end
    std::cin >> start >> end;
    
    dijkstra();
    
    //output ans
    intPair ending = goodPair.at(end);
    
    if (ending.first == INT_MAX or ending.second >= hullPoints){
        std::cout << "-1\n";
    }
    else{
        std::cout << ending.first << '\n';
    }
}