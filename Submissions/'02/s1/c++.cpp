//i/o
#include <iostream>

//for getting inf
#include <cmath>

//vectors for keeping track
#include <vector>

//getting regular min
#include <algorithm>

//getting sum of a vector
#include <numeric>

int inf = pow(2, 31) - 1;

int leastTickets = inf;


int getCombs (int moneyLeft, int ticketPos, std::vector<int> ticketsRn, std::vector<int> ticketCost){
    
    if (moneyLeft == 0){
        
        //Output tickets
        std::cout << "# of PINK is " << ticketsRn[0];
        std::cout << " # of GREEN is " << ticketsRn[1];
        std::cout << " # of RED is " << ticketsRn[2];
        std::cout << " # of ORANGE is " << ticketsRn[3];
        
        std::cout << '\n';
        
        //get mininmum # of tickets
        leastTickets = std::min(leastTickets, std::accumulate(ticketsRn.begin(), ticketsRn.end(), 0));
        
        return 1;
    }
    
    int combs = 0;
    
    for (int i = ticketPos; i != 4; i ++){
        
        int moneyAfter = moneyLeft - ticketCost[i];
        
        if (moneyAfter < 0){
            continue;
        }
        
        ticketsRn[i] += 1;
        combs += getCombs (moneyAfter, i, ticketsRn, ticketCost);
        ticketsRn[i] -= 1;
    }
    
    return combs;
    
}


int main() {
    
    std::vector <int> ticketCost (4, -1);
    std::vector <int> enptyFunctionPass (4, 0);
    
    int target, input;
    
    for (int i = 0; i != 4; i ++){
        std::cin >> input;
        ticketCost[i] = input;
    }
    
    std::cin >> target;
    
    int combsTotal = getCombs(target, 0, enptyFunctionPass, ticketCost);
    
    std::cout << "Total combinations is " << combsTotal << "." << '\n';
    std::cout << "Minimum number of tickets to print is " << leastTickets << "." << '\n';
    
}