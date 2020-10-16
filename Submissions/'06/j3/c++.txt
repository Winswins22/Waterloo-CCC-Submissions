#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <vector <char>> phone {
  {'a', 'b', 'c'},
  {'d', 'e', 'f'},
  {'g', 'h', 'i'},
  {'j', 'k', 'l'},
  {'m', 'n', 'o'},
  {'p', 'q', 'r', 's'},
  {'t', 'u', 'v'},
  {'w', 'x', 'y', 'z'},
};

int getRow (char search){

  for (int r = 0; r != phone.size(); r ++){

    for (int c = 0; c != phone[r].size(); c ++){

      if (search == phone[r][c]){
        return r;
      }

    }

  }

}

int getCol (char search){

  for (int r = 0; r != phone.size(); r ++){

    for (int c = 0; c != phone[r].size(); c ++){

      if (search == phone[r][c]){
        return c;
      }

    }

  }

}


int main() {

  while (true){

    int time = 0;
    int row = -1, col = -1;
    int newRow = 0, newCol = 0;

    string input;
    cin >> input;

    if (input == "halt"){
      break;
    }

    for (char chr : input){

      newRow = getRow (chr);
      newCol = getCol (chr);

      if (newRow == row and row != -1){
        time += 2;
      }

      time += newCol + 1;

      row = newRow;
      col = newCol;

    }
      
    cout << time << '\n';
  }



}