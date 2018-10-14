#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int n;
    cin >> n;
    
    if(n < 42)
        cout << "More" << endl;
    else if(n > 42)
        cout << "Less" << endl;
    else
        cout << "Bingo!" << endl;

    return 0;
}
