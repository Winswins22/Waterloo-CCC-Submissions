// functions use std::cerr
// not the neatest/most efficient code, but it works for debugging
// std::cerr output does not appear when submitting to DMOJ

// to use, you can change the type of the data structure and the length of it.

#include <iostream>

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <utility>
#include <array>

#include <algorithm>
#include <climits>

void _template_ (std::set<long long> x, bool newLine = false){
  //works also with empty sets
  std::cerr << "m_set(";

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

void print (std::pair <long long, long long> x, bool newLine = false){
  //works only on full pairs
  if (newLine){
    std::cerr << "(" << x.first << ", " << x.second << ")\n";
  }
  else{
    std::cerr << "(" << x.first << ", " << x.second << ")";
  }
}

void print (std::array<long long, 3> x, bool newLine = false){
  // parameter for x may need to be changed
  std::cerr << "array(";

  if (not x.empty()){
    long long iters = 1;
    long long arraySize = x.size();

    for (auto i : x){
      std::cerr << i;

      if (iters == arraySize){
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






// example of changing _template_
void print (std::multiset<long long> x, bool newLine = false){
  //works also with empty sets
  std::cerr << "m_set(";

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

void print (std::set<long long> x, bool newLine = false){
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

void print (std::unordered_set<long long> x, bool newLine = false){
  //works also with empty sets
  std::cerr << "u_set(";

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

void print (std::vector<long long> x, bool newLine = false){
  //works also with empty vectors
  std::cerr << "vector(";

  if (not x.empty()){
    long long iters = 1;
    long long vectorSize = x.size();

    for (auto i : x){
      std::cerr << i;

      if (iters == vectorSize){
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

// changing _template_ to deal with more complicated data types
void print (std::set< std::pair<long long, long long> > x, bool newLine = false){
  //works also with empty sets
  std::cerr << "m_set(";

  if (not x.empty()){
    long long iters = 1;
    long long setSize = x.size();

    for (auto i : x){
      // change here -----------
      print(i);
      // -----------------------

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



int main() {
  std::array <long long, 3> t {1, 2, 541};
  print(t, true);
}