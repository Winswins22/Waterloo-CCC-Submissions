#include <iostream>
#include <array>
#include <utility>
#include <cmath>

typedef long long ll;
typedef std::pair <ll, ll> pll;

#define f first
#define s second

// only 1 .. 2000009 will be used, ignore index 0
std::array <ll, 2000010> sieve;

void changeSieve(ll num){
    
    ll index = num * 2;
    
    while (index < 2000010){
        sieve.at(index) = false;
        index += num;
    }
    
}

void initSieve(){
    
    // set sieve
    for (ll i = 0; i != 2000010; i ++){
        sieve[i] = true;
    }
    sieve.at(0) = false;
    sieve.at(1) = false;
    
    // actually sieve
    for (ll i = 2; i != 2000010; i ++){
        // if its prime, set multiples to false
        if (sieve.at(i)){
            changeSieve(i);
        }
    }
    
}

pll findPrimes(ll target){
    
    for (ll i = 2; i < ceil(sqrt(target)) + 1; i ++){
        
        if (not sieve.at(i)){
            continue;
        }
        
        if (sieve.at(target - i)){
            return {i, target - i};
        }
        
    }
    
}

int main(){
    
    initSieve();
    
    ll inputs;
    std::cin >> inputs;
    
    ll target;
    pll primes;
    
    for (ll i = 0; i != inputs; i ++){
        
        std::cin >> target;
        target *= 2;
        
        // find primes
        primes = findPrimes(target);
        
        std::cout << primes.f << " " << primes.s << '\n';
    }
    
}