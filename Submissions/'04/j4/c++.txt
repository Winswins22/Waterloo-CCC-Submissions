#include <iostream>
#include <vector>
#include <string>

#define pb push_back
typedef long long ll;

std::vector <ll> shift;
std::string keyword;

std::string toProcess;
std::vector <char> toEncrypt;
std::vector <char> encrypted;

bool isAscii (ll converted){
    
    if (0 <= converted and converted <= 25){
        return true;
    }
    return false;
    
}

ll chrint (char i){
    ll ascii_val = i;
    ascii_val -= 65;
    
    return ascii_val;
}



int main(){
    
    std::getline(std::cin, keyword);
    std::getline(std::cin, toProcess);
    
    //convert ascii to amoount of shift
    ll ascii_val;
    
    for (char i : keyword){
        ascii_val = chrint(i);
        shift.pb(ascii_val);
    }
    
    // processed toProcess to remove non-letters
    for (char i : toProcess){
        if (isAscii(chrint(i))){
            toEncrypt.pb(i);
        }
    }
    
    // shift toEncrypt and store it in encrypted
    ll idx;
    ll new_num;
    char new_letter;
    
    for (ll i = 0; i != toEncrypt.size(); i ++){
        idx = i % shift.size();
        
        // new_num = (toEncrypt.at(i)) + shift.at(idx));
        new_num = toEncrypt.at(i);
        new_num += shift.at(idx);
        
        if (new_num > 90){
            new_num -= 26;
        }
        
        new_letter = new_num;
        encrypted.pb(new_letter);
    }
    
    for (char i : encrypted){
        std::cout << i;
    }
    std::cout << '\n';
}