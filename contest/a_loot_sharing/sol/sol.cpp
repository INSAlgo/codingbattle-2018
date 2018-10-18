#include <iostream>
using namespace std;

int main() {
    long long int b, t, n;
    cin >> b >> t >> n;
    if(2*b + 3*t <= n)
        cout << "LOOT!" << endl;
    else
        cout << "RHUM!" << endl;
    return 0;
}