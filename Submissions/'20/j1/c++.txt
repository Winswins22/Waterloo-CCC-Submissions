#include <iostream>

int main()
{
  int s, m, l, total;

  std::cin >> s >> m >> l;

  total = s + m * 2 + l * 3;

  if (total >= 10){
    std::cout << "happy";
  }
  else {
    std::cout << "sad";
  }


}