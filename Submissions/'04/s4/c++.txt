#include <iostream>
#include <vector>

//dict
#include <unordered_map>

//reverse sort + min
#include <algorithm>

//inf
#include <cmath>

int inf = pow(2, 31) - 1;

//Format:
// {distance : clubsNeeded}
std::unordered_map <int, int> shortcuts;

//In DFS, inf - 1 is the stop signal.
int DFS (int position, int distanceLeft, int clubsUsed, const std::vector <int>& clubs){
    
    //Base Case
    if (distanceLeft == 0) {
        return clubsUsed;
    }
    
    //DP - stop early
    if (shortcuts.count(distanceLeft) == 1){
      if (shortcuts.at(distanceLeft) == inf - 1){
        return inf - 1;
      }
    }
    
    //DP BC
    if (shortcuts.at(distanceLeft) != inf && shortcuts.at(distanceLeft) != inf - 1) {
        return clubsUsed + shortcuts.at(distanceLeft);
    }
    
    //Recursion
    int bestResult = inf - 1, result;
    
    int clubsAfter = clubsUsed + 1, distanceAfter;
    
    for (int i = position; i != clubs.size(); i ++){
        
        distanceAfter = distanceLeft - clubs[i];
        
        if (distanceAfter < 0){
            continue;
        }
        
        result = DFS(i, distanceAfter, clubsAfter, clubs);
        
        bestResult = std::min(bestResult, result);
    }
    
    shortcuts.at(distanceLeft) = bestResult;
    return bestResult;
    
}

int main() {
    
    int dist, temp, numClubs, result;
    std::vector <int> clubs;
    
    std::cin >> dist;
    std::cin >> numClubs;
    
    for (int i = 0; i != numClubs; i ++){
        std::cin >> temp;
        clubs.push_back(temp);
    }
    
    for (int j = 1; j <= dist; j ++){
        shortcuts.insert({j ,inf});
    }

    for (int k : clubs){
        shortcuts.at(k) = 1;
    }

    std::sort(clubs.begin(), clubs.end(), std::greater<int>());
    
    result = DFS(0, dist, 0, clubs);
    
    

    if (result == inf - 1){
        std::cout << "Roberta acknowledges defeat." << '\n';
    }
    else {
        std::cout << "Roberta wins in " << result << " strokes." << '\n';
    } 
}