#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

int main(int argc, char **argv) {
    lli p, l, g, cpt = 0;
    cin >> p >> l >> g;
    for(lli x=0; x <= p && x*x <= g; x++) {
        for(lli y=0; y<l; y++) {
            lli r = x*x + x*y + y;
            if(r == g) {
                cpt++;
            } else if(r > g) {
                break;
            }
        }
    }
    cout << cpt;
    return 0;
}
