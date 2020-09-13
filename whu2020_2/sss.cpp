#include <iostream>
using namespace std;
int main() {
    for(int i = 1; i <= 27; i++)
        cout << i*i*i%28 <<endl;
    return 0;
}