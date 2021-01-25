#include <iostream>
#include <sstream> // std::stringstream

#include <vector>
#include <string> 

std::vector <char> empty;
std::vector <std::string> empty2;

std::vector <std::vector<std::string>> spreadsheet;

bool isEquation (std::string check){
    
    try {
      std::stoi(check);
      return false;
    }
    catch (std::invalid_argument){
      return true;
    }
    
}

int ord (char letter){
    int x = letter - 65;
    return x;
}

int intord (char number){
  int x = number - 48;
  return x;
}

std::vector<std::vector<char>> split (std::string toSplit){

  std::vector<std::vector<char>> processed;
  char splitChar = '+';

  std::stringstream input (toSplit);
  std::string temp;
  std::vector<char> build {'a', 'a'};

  while (std::getline (input, temp, splitChar)){
    build[0] = temp[0];
    build[1] = temp[1];

    processed.push_back(build);
  }

  return processed;
}

//Checks if any tiles' values can be calculated without touching a second equation. If so, changes the spreadsheet to contian the value.
void iterateOnce(){
    
    int calcRow, calcCol;
    
    int searchSum = 0;
    bool abortCurrentSearch = false;
    
    std::string itemAtNode, searchingItemAtNode;
    std::vector<std::vector<char>> instructions;
    
    for (int row = 0; row != spreadsheet.size(); row ++){
        for (int col = 0; col != spreadsheet[row].size(); col ++){
            
            itemAtNode = spreadsheet.at(row).at(col);
            
            abortCurrentSearch = false;
            searchSum = 0;

            //Do a quick search to check if possible to calc value
            if (isEquation(itemAtNode)){
                
                instructions = split (itemAtNode);
                
                for (std::vector<char> i : instructions){
                    
                    calcRow = ord(i[0]);
                    calcCol = intord(i[1]) - 1;
                    
                    searchingItemAtNode = spreadsheet.at(calcRow).at(calcCol);
                    
                    if (isEquation (searchingItemAtNode)){
                        abortCurrentSearch = true;
                        break;
                    }

                    searchSum += std::stoi(searchingItemAtNode);
                    
                }
                
                if (not abortCurrentSearch){
                    spreadsheet[row][col] = std::to_string(searchSum);
                }
                
            }
            
        }
    }
    
}

int main(){
    
    // get spreadsheet info
    std::vector<std::string> storeRow;
    std::string valueAtRowCol;
    
    for (int row = 0; row != 10; row ++){
        
        for (int col = 0; col != 9; col ++){
            std::cin >> valueAtRowCol;
            storeRow.push_back(valueAtRowCol);
        }
        
        spreadsheet.push_back(storeRow);
        storeRow = empty2;
    }
    
    //iterate 100 times (spreadsheet is 9 * 10 == 90 necessary searches, but extra searches just in case)
    for (int numSearches = 0; numSearches != 100; numSearches ++){
        iterateOnce();
    }

    //Iterate once again, but if theres is an equation, make it an asterisk
    std::string valueAtNode;
    
    for (int r = 0; r != 10; r ++){
        
        for (int c = 0; c != 9; c ++){
            
            valueAtNode = spreadsheet.at(r).at(c);
            
            if (isEquation (valueAtNode)){
                spreadsheet[r][c] = "*";
            }
            
        }
        
    }
    
    //Output the spreadsheet
    for (int i = 0; i != spreadsheet.size(); i ++){
        for (int j = 0; j != spreadsheet[i].size(); j ++){
            
            std::cout << spreadsheet[i][j];
            
            if (j != spreadsheet[i].size() - 1){ // not the last value to output
                std::cout << ' ';
            }
            
        }
        std::cout << '\n';
    }
    
}