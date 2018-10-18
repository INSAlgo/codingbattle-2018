#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, n;

vector<int> hats;
vector<int> pos;

bool backtrack(vector<int>& state, int last_covered_pos, int current_pos_index) {
    // we have reached the last position
    if(current_pos_index == n) {
        if(last_covered_pos >= l) {
            return true;
        }
        return false;
    }
    
    // find the widest hat we haven't placed yet
    int max_hat = 0;
    for(int i=0; i<n; ++i) {
        if(state[i] == 0 && hats[i] > max_hat) {
            max_hat = hats[i];
        }
    }
    // if two times the widest hat can't cover one of the remaining gaps, go back
    for(int i=current_pos_index; i < n-1; ++i) {
        if(last_covered_pos < pos[i] && pos[i+1] - pos[i] - 1 > 2*max_hat) {
            return false;
        }
    }
    if(last_covered_pos < l && pos[n-1] + max_hat < l) {
        return false;
    }
    
    // consider every hat we haven't placed yet
    for(int i=0; i<n; ++i) {
        if(state[i] == 0) {
            // if placing the current hat here can lead to a solution
            if(pos[current_pos_index] - hats[i] - 1 <= last_covered_pos) {
                // push the current hat here and recurse to the next position
                state[i] = 1;
                if(backtrack(state, max(pos[current_pos_index] + hats[i], last_covered_pos), current_pos_index + 1)) {
                    // a solution was found !
                    return true;
                }
                // pop back the current hat before we evaluate the other hats
                state[i] = 0;
            }
        }
    }
    return false;
}

int main() {
    cin >> l >> n;
    pos.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> pos[i];
    }
    hats.resize(n);
    for(int i=0; i<n; ++i) {
        cin >> hats[i];
    }
    sort(hats.begin(), hats.end());
    
    vector<int> state(n, 0);
    if(backtrack(state, 1, 0)) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}