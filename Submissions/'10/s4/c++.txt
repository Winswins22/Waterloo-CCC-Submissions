#include <iostream>
#include <cstdio>

#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <algorithm>

#include <functional>
#include <climits>

typedef long long ll;
typedef std::pair <ll, ll> pll;
typedef std::array <ll, 3> al3;

#define pb push_back 
#define f first
#define s second

// Debug Tools
// ------------------------------------

void outSet (std::set<long long> x, bool newLine = false){
  //works also with empty sets
  std::cerr << "set(";

  if (not x.empty()){
    long long iters = 1;
    long long setSize = x.size();

    for (long long i : x){
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

void outSet (std::unordered_set<long long> x, bool newLine = false){
  //works also with empty sets
  std::cerr << "u_set(";

  if (not x.empty()){
    long long iters = 1;
    long long setSize = x.size();

    for (long long i : x){
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

void outPair (std::pair <long long, long long> x, bool newLine = false){
  //works only on full pairs
  if (newLine){
    std::cerr << "(" << x.first << ", " << x.second << ")\n";
  }
  else{
    std::cerr << "(" << x.first << ", " << x.second << ")";
  }
}

void outVect (std::vector<long long> x, bool newLine = false){
  //works also with empty sets
  std::cerr << "vector(";

  if (not x.empty()){
    long long iters = 1;
    long long setSize = x.size();

    for (long long i : x){
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

void outArr (std::array<long long, 3> x, bool newLine = false){
  // parameter for x may need to be changed
  std::cerr << "array(";

  if (not x.empty()){
    long long iters = 1;
    long long setSize = x.size();

    for (long long i : x){
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

// Vars
// ------------------------------------

/*  */
// Adj List Creation Vars

ll shapeNum = 0;

// shapeNum : {(cost, corner1, corner2) ...}
std::unordered_map <ll, std::set<al3> > shapeEdges;

std::set<al3> allEdges;

// edge : {shapeNums, ...}
std::map <al3, std::unordered_set<ll> > edgeWhere;

/*  */
//Prims Vars

// node : {(cost, node), ...}
std::unordered_map <ll, std::set <pll> > graph;

// node : (cost)
std::unordered_map <ll, ll> shortPaths;
std::unordered_set <ll> trvl;

// ------------------------------------
// Adj List Functions

// input spaghetti -> edges, where they are (cost, corner1, corner2)
// Contains duplicates (i.e: (1, 2, 3), (1, 3, 2))
std::set<al3> getEdges(ll vectorSize, std::vector<ll> corners, std::vector<ll> costs){
    
    std::set<al3> returning;
    ll index1, index2;
    
    for (ll i = 0; i != vectorSize; i ++){
        
        index1 = i;
        index2 = (i + 1) % vectorSize;
        
        returning.insert({costs.at(index1), corners.at(index1), corners.at(index2)});
        returning.insert({costs.at(index1), corners.at(index2), corners.at(index1)});
        
    }
    /*std::cerr << "corners\n";
    outVect(corners, true);
    std::cerr << "costs\n";
    outVect(costs ,true);
    std::cerr << "Testing getEdges()\n";
    for (al3 i : returning){
        outArr(i, true);
    }
    */

    return returning;
    
}

// ------------------------------------
// Prims functions

void resetSPaths(){
    shortPaths.clear();
    
    for (ll i = 0; i != shapeNum; i ++){
        shortPaths[i] = {LLONG_MAX};
    }
    shortPaths[LLONG_MAX] = {LLONG_MAX};
}

ll getAns(){
    
    ll ans = 0;
    
    for (std::pair<ll, ll> i : shortPaths){
        
        if (i.s == LLONG_MAX and i.f != LLONG_MAX){
            return LLONG_MAX;
        }
        if (i.s == LLONG_MAX){
            continue;
        }
        ans += i.s;
        
    }
    
    return ans;
}


bool isGood(pll node){
    
    ll sPath = shortPaths.at(node.s);
    
    if (node.f <= sPath){
        return true;
    }
    return false;
    
}

bool isBetter(pll i){
    
    ll sPath = shortPaths.at(i.s);
    
    if (i.f < sPath){
        return true;
    }
    return false;
    
}

void prims(bool canGoOutside){
    
    // pll == (node)
    std::priority_queue <pll, std::vector<pll>, std::greater<pll> > pq;
    
    pll init = {0, 0};
    
    pq.push(init);
    shortPaths.at(0) = 0;
    
    
    pll node;
    
    while (not pq.empty()){
        
        node = pq.top();
        pq.pop();

        std::cerr << "Prims: ";
        outPair(node, true);
        
        if (not isGood(node)){
            continue;
        }
        if (trvl.find(node.s) != trvl.end()){
            continue;
        }

        trvl.insert(node.s);
        
        for (pll i : graph.at(node.s)){
            
            outPair(i, true);
            /*
            // check for going to the node it came from
            if (shortPaths.at(node.s).s == i.s){
                continue;
            }
            */
            
            if (not isBetter(i)){
                continue;
            }
            if (trvl.find(i.s) != trvl.end()){
                continue;
            }
            // check for going outside if you cant
            if (i.s == LLONG_MAX and not canGoOutside){
                continue;
            }
            
            std::cerr << "^ Added\n";
            shortPaths.at(i.s) = i.f;
            pq.push(i);
        }
        
    }
    
}

// ------------------------------------
// int main

int main(){
    
      
    ll nodes;
    std::cin >> nodes;
    
    // build shapeEdges
    ll inputTimes;
    ll temp;
    std::vector<ll> corners;
    std::vector<ll> costs;
    
    for (ll i = 0; i != nodes; i ++){
        
        std::cin >> inputTimes;
        corners.clear();
        costs.clear();
        
        for (ll j = 0; j != inputTimes; j ++){
            std::cin >> temp;
            corners.pb(temp);
        }
        
        for (ll j = 0; j != inputTimes; j ++){
            std::cin >> temp;
            costs.pb(temp);
        }
        
        shapeEdges[shapeNum] = getEdges(inputTimes, corners, costs);
        shapeNum ++;
        
        for (al3 j : shapeEdges.at(shapeNum - 1)){
            allEdges.insert(j);
        }
    }
    
    // build edgeWhere
    for (al3 i : allEdges){
        edgeWhere[i] = {};
    }
    
    for (std::pair <ll, std::set<al3> > i : shapeEdges){
        for (al3 j : i.s){
            edgeWhere.at(j).insert(i.f);
        }
    }
    
    // build graph
    for (ll i = 0; i != shapeNum; i ++){
        graph[i] = {};
    }
    graph[LLONG_MAX] = {};
    
    for (std::pair <al3, std::unordered_set<ll> > i : edgeWhere){
        
        // check if only 1 connection. If yes, connect to outside
        if (i.s.size() == 1){
            for (ll j : i.s){
                graph.at(j).insert({i.f.at(0), LLONG_MAX});
                graph.at(LLONG_MAX).insert({i.f.at(0), j});
            }
            continue;
        }
        
        //multiple connections
        for (ll first : i.s){
            for (ll second : i.s){
                // check for self-loops
                if (first == second){
                    continue;
                }
                graph.at(first).insert({i.f.at(0), second});
                graph.at(second).insert({i.f.at(0), first});
            }
        }
        
    }
    // use prims ftw
    ll bestRes = LLONG_MAX;
    
    resetSPaths();
    prims (false);
    bestRes = std::min(bestRes, getAns());

    std::cerr << "\nshortPaths\n";

    for (std::pair<ll, ll> i : shortPaths){
      std::cerr << i.f << " : " << i.s << '\n';
    }
    
    trvl.clear();
    resetSPaths();
    prims (true);
    bestRes = std::min(bestRes, getAns());
    
    std::cout << bestRes << '\n';

    
    std::cerr << "\n\nDebugging\n";

    std::cerr << "shapeEdges\n";

    for (std::pair<ll, std::set<al3> > i : shapeEdges){
        std::cerr << i.f << " : ";

        for (al3 j : i.s){
          outArr(j);
          std::cerr << " ";
        }

        std::cerr << '\n';
    }

    std::cerr << "\nedgeWhere\n";

    for (std::pair<al3, std::unordered_set<ll> > i : edgeWhere){
        outArr(i.f);

        std::cerr << " : ";

        outSet(i.s, true);
    }

    std::cerr << "\ngraph\n";

    for (std::pair<ll, std::set <pll> > i : graph){

        std::cerr << i.f << " : ";

        for (pll j : i.s){
          outPair(j);
          std::cerr << " ";
        }

        std::cerr << '\n';
    }
    
    std::cerr << "\nshortPaths\n";

    for (std::pair<ll, ll> i : shortPaths){
      std::cerr << i.f << " : " << i.s << '\n';
    }
    
    
}