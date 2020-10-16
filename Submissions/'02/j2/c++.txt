#include <iostream>
#include <string>

using namespace std;

bool isVowel (string x){

  if (x == "a"){
    return 1;
  }
  else if (x == "e"){
    return 1;
  }
  else if (x == "i"){
    return 1;
  }
  else if (x == "o"){
    return 1;
  }
  else if (x == "u"){
    return 1;
  }

  return 0;
}

int main() {
    
    string input, last2;
    cin >> input;
    
    int len = input.length();
    
    while (input != "quit!"){
    
    if (len > 4){
        
        last2 = input.substr(len - 2, 2);
        
        if (last2 == "or" && ! isVowel(input.substr(len - 3, 1))){
            cout << input.substr(0, len - 2) << "our" << endl;
        }
        else {
            cout << input << endl;
        }
        
    }
    else {
        cout << input << endl;
    }
    cin >> input;
    len = input.length();
    }

}