#include <iostream>
#include <string>
using namespace std;

typedef long long int lli;

int main() {
    lli g, n, p, c, best_offer = 0;
    cin >> g >> n; // n won't be used
    
    string name, best_trainer;

    // Go through all trainers in the given order
    while(cin >> name >> p >> c) {
        // Compute how many parrots we can buy from this trainer
        lli nb_parrots = (g - c) / p;

        // Check if it's better than the best encountered yet
        if(nb_parrots > best_offer) {
            best_offer = nb_parrots;
            best_trainer = name;
        }
    }
    
    if(best_offer == 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << best_offer << endl << best_trainer << endl;
    return 0;
}
