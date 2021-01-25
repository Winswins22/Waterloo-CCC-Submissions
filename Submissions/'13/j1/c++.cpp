#include <iostream>

using namespace std;

int main() {
    
    int a, b;
    cin >> a >> b;
    
    if (a > b)
        cout << abs(a-b) + a;
    else
        cout << abs(a-b) + b;
    
    return 0;
}