#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char** argv) {
	string l;
	int n;
	cin >> l >> n;
	
	map<string, int> det_cycle{};
	int counter[10] = {0};
	
	int i = 0;
	while(i < n) {
	    // Count occurences of every digit in the current number's string
		for (int j = 0; j < l.length(); j++) {
			counter[(int)(l[j] - '0')]++;
		}
        
        // Create the new number's string
		l = "";
		for (int j = 0; j < 10; j++) {
			if (counter[j] != 0) {
				l += to_string(counter[j]) + to_string(j);
				counter[j] = 0;
			}
		}
		
		// Detect cycles
		map<string, int>::iterator it = det_cycle.find(l);
		if(it != det_cycle.end()) {
		    // Cycle detected, skip as many steps as possible
		    int diff = i - it->second;
		    int skip = (n - i - 1) / diff;
		    i += skip * diff + 1;
		} else {
		    // No cycle detected, carry on
		    det_cycle[l] = i;
		    i++;
		}
	}
	cout << l << endl;
	return 0;
}
