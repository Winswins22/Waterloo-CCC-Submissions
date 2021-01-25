#include <iostream>

#include <vector>
#include <set>
#include <unordered_set>
#include <array>
#include <utility>
#include <map>
#include <string>
#include <queue>

#include <climits>
#include <algorithm>

typedef long long ll;
typedef std::pair<ll, ll> pll;

#define f first
#define s second

/*
// Notable test case for me
4 5
WWWWW
WWC.W
WSRUW
WWWWW
// Answer is -1
*/

//------------------------------------------------
// Debugging Functions
//------------------------------------------------

void outPair (std::pair <long long, long long> x, bool newLine = false){
  //works only on full pairs
  if (newLine){
    std::cerr << "(" << x.first << ", " << x.second << ")\n";
  }
  else{
    std::cerr << "(" << x.first << ", " << x.second << ")";
  }
}

void outSet (std::set<long long> x, bool newLine = false){
  //works also with empty sets
  std::cerr << "set(";

  if (not x.empty()){
    long long iters = 1;
    long long setSize = x.size();

    for (auto i : x){
      std::cerr << i;

      if (iters == setSize){
        std::cerr << ")";
      }
      else{
        std::cerr << ", ";
      }

      iters ++;
    }
  }
  else{
    std::cerr << ")";
  }

  if (newLine){
    std::cerr << '\n';
  }

}

void outSet (std::set<pll> x, bool newLine = false){
  //works also with empty sets
  std::cerr << "set(";

  if (not x.empty()){
    long long iters = 1;
    long long setSize = x.size();

    for (auto i : x){
      outPair(i);

      if (iters == setSize){
        std::cerr << ")";
      }
      else{
        std::cerr << ", ";
      }

      iters ++;
    }
  }
  else{
    std::cerr << ")";
  }

  if (newLine){
    std::cerr << '\n';
  }

}

//------------------------------------------------
// General Vars + Functions
//------------------------------------------------

// amount of rows and cols in the graph
ll rows, cols;

std::array <char, 4> conveyors = {'R', 'L', 'D', 'U'};

// move vertically
std::array <ll, 4> moveRow = {-1, 1, 0, 0};
// move horizontally
std::array <ll, 4> moveCol = {0, 0, -1, 1};

bool inBorders (pll coords){
    
    if ((0 <= coords.f and coords.f <= rows - 1) and (0 <= coords.s and coords.s <= cols - 1)){
        return true;
    }
    return false;
    
}

ll getIndex (char conveyor){
    
    auto itr = std::find (conveyors.begin(), conveyors.end(), conveyor);
    
    if (itr != conveyors.end()){
        return itr - conveyors.begin();
    }
    // invalid
    return INT_MAX;
    
}

//------------------------------------------------
// Graph Vars + Functions
//------------------------------------------------

std::vector <std::string> maze;

// pll is the (row, col) pair used to index the maze. (0, 0) is the top left corner
std::map <pll, std::set<pll> > graph;

void buildOutboundConnections(pll tile){

    std::set<pll> value = {};
    
    pll newCoords;
    char item;
    
    //std::cerr << "Outbound base: ";
    //outPair(tile, true);

    // move up, down, left, right
    for (ll idx = 0; idx != moveRow.size(); idx ++){
        // calc new coords
        newCoords = {tile.f + moveRow.at(idx), tile.s + moveCol.at(idx)};
        //std::cerr << "  New Coords: ";
        //outPair(newCoords, true);
        
        if (not inBorders (newCoords)){
            //std::cerr << "  Not in borders\n";
            continue;
        }
        
        item = maze.at(newCoords.f).at(newCoords.s);
        
        if (item == 'C' or item == 'W'){
            //std::cerr << "  Is cam or wall\n";
            continue;
        }
        
        //std::cerr << "  Successfully inserted\n";
        value.insert(newCoords);
    }
    
    //std::cerr << "Final value: ";
    //outSet(value, true);
    graph[tile] = value;
}

//------------------------------------------------
// Camera Vars + Functions
//------------------------------------------------

std::set <pll> cams;

// tiles that are being watched by camera
std::set <pll> cammed;

void activateCameras(){
    
    pll moving;
    char item;
    
    // go up, down, left, and right and add all tiles until you hit a wall, and dont add conveyors
    for (pll i : cams){
        
        // d == direction
        for (ll d = 0; d != moveRow.size(); d ++){
            
            moving = i;
            
            // move repeatedly in one direction
            while (true){
                
                moving.f += moveRow.at(d);
                moving.s += moveCol.at(d);
                
                item = maze.at(moving.f).at(moving.s);
                
                if (item == 'C' or item == 'W' or not inBorders(moving)){
                    break;
                }
                else if (item == '.' or item == 'S'){
                    cammed.insert(moving);
                }
                else{
                    // must be a conveyor
                    continue;
                }
                
                
            }
            
        }
        
    }
    
}

//------------------------------------------------
// Conveyor Vars + Functions
//------------------------------------------------

//this was supposed to be in graph but had to be moved for reason below
pll startLocation;

//this was supposed to be in buildPathLength, but since getConveyorTarget needs to use this too, it has to be in global scope
std::set <pll> trvl = {startLocation};

bool isConveyor (pll coords){
    
    char item = maze.at(coords.f).at(coords.s);
    
    if (getIndex(item) != INT_MAX){
        return true;
    }
    return false;
    
}

pll getConveyorTarget(pll currTile){
    
    // Note that is the conveyor has already been used, it means that a more optimal path has been already reached
    if (trvl.find(currTile) != trvl.end()){
        return {INT_MAX, INT_MAX};
    }

    char item = maze.at(currTile.f).at(currTile.s);
    
    // if conveyor, move to next location, then save result
    if (isConveyor(currTile)){

        // prevent infinite loops
        if (trvl.find(currTile) != trvl.end()){
            return {INT_MAX, INT_MAX};
        }
        trvl.insert(currTile);

        pll newCoords = {currTile.f - moveCol[getIndex(item)], currTile.s - moveRow[getIndex(item)]};
        return getConveyorTarget(newCoords);
    }
    // if valid, return answer
    else if (item == 'S' or item == '.'){
        return currTile;
    }
    
    // if invalid, return
    return {INT_MAX, INT_MAX};
    
}

//------------------------------------------------
// Graph Search
//------------------------------------------------

// how long it took to get to the tile.
std::map <pll, ll> pathLength;

// gets info from maze
// specifically gets cameras, start location, and calls buildOutboundConnections()
void getInfo(){
    
    char mazeItem;
    
    for (ll r = 0; r != rows; r ++){
        for (ll c = 0; c != cols; c ++){
            
            mazeItem = maze.at(r).at(c);
            
            if (mazeItem == '.'){
                buildOutboundConnections({r, c});
            }
            
            else if (mazeItem == 'C'){
                cams.insert({r, c});
                cammed.insert({r, c});
            }
            
            else if (mazeItem == 'S'){
                startLocation = {r, c};
                buildOutboundConnections({r, c});
            }
            // prevent std::out_of_range
            else{
                graph[{r, c}] = {};
            }
            
        }
    }
    
}



// set all to INT_MAX
void initPathLength(){
    
    for (ll r = 0; r != rows; r ++){
        for (ll c = 0; c != cols; c ++){
            pathLength[{r, c}] = INT_MAX;
        }
    }
    
}

// find path lengths using BFS
// calls getConveyorTarget()
void buildPathLength(pll start){
    
    //this was supposed to be in here, but since getConveyorTarget needs to use this too, it has to be in global scope
    //std::set <pll> trvl = {start};
    
    std::queue <pll> current;
    std::queue <pll> next;
    next.push(start);

    pll conveyorTarget;
    
    pll node;
    ll distanceFromStart = 1;

    // counter edge case where robot starts in the view of a camera
    if (cammed.find(start) != cammed.end()){
        return;
    }
    
    while (not next.empty()){
        
        //std::cerr << "\nSwitching out queues!\n";
        current = next;
        next = {};

        while (not current.empty()){

            node = current.front();
            current.pop();

            //std::cerr << "Current Node: ";
            //outPair(node, true);
            
            trvl.insert(node);

            for (pll i : graph.at(node)){
                
                //std::cerr << "  Checking: ";
                //outPair(i, true);

                if (i == pll({INT_MAX, INT_MAX})){
                    //std::cerr << "Invalid\n";
                    continue;
                }
                
                if (trvl.find(i) != trvl.end()){
                    //std::cerr << "Already went to\n";
                    continue;
                }

                if (cammed.find(i) != cammed.end()){
                    continue;
                }
                
                if (isConveyor(i)){

                    //std::cerr << "  Detected a conveyor!\n";
                    conveyorTarget = getConveyorTarget(i);
                    trvl.insert(i);

                    //std::cerr << "    The conveyor's target is: ";
                    //outPair(conveyorTarget, true);

                    if (conveyorTarget != pll({INT_MAX, INT_MAX})){

                        // make sure not travelled to before
                        if (trvl.find(conveyorTarget) != trvl.end()){
                            //std::cerr << "    Already went to\n";
                            continue;
                        }
                        
                        // make sure not in view of cameras
                        if (cammed.find(conveyorTarget) != cammed.end()){
                            continue;
                        }

                        pathLength.at(conveyorTarget) = distanceFromStart;
                        //std::cerr << "    Distance cost: " << pathLength.at(conveyorTarget) << '\n';

                        trvl.insert(conveyorTarget);
                        next.push(conveyorTarget);
                    }
                    
                }
                else{
                    //std::cerr << "  Added and optimal\n";
                    pathLength.at(i) = distanceFromStart;
                    trvl.insert(i);
                    next.push(i);
                }
                
            }
            
            
        }

        distanceFromStart ++;
        
    }
    
}

// loop thru maze and retrieve information from pathLength
void outputAnswers(){
    
    for (ll r = 0; r != rows; r ++){
        for (ll c = 0; c != cols; c ++){
            
            if (maze.at(r).at(c) != '.'){
                continue;
            }
            
            if (pathLength.at({r, c}) == INT_MAX){
                std::cout << "-1\n";
            }
            else{
                std::cout << pathLength.at({r, c}) << '\n';
            }
            
        }
    }
    
}

//------------------------------------------------
// int main()
//------------------------------------------------

int main(){
    
    // get input
    std::cin >> rows >> cols;
    
    std::string currRow;
    
    for (ll i = 0; i != rows; i ++){
        std::cin >> currRow;
        maze.push_back(currRow);
    }
    
    // build the graph, and detect start point and cameras
    getInfo();
    
    // self-explanatory
    activateCameras();
    
    // set all path length values to INT_MAX
    initPathLength();

    // do a BFS
    buildPathLength(startLocation);
    
    // print answers directly to screen
    outputAnswers();
    
    //------------------------------------------------
    /*
    // Outputter
    std::cerr << "Graph\n";

    for (std::pair<pll, std::set<pll> > i : graph){
        outPair(i.f);
        std::cerr << " : ";
        outSet(i.s, true);
    }
    
    std::cerr << "Cammed: ";
    outSet(cammed);
    */
    //------------------------------------------------

}