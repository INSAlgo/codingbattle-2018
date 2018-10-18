#include <iostream>
#include <cmath>
#include <string>
#include <map>

using namespace std;


std::map<char, int> dico = {
    {'a', 1}, {'e', 2}, {'i', 3}, {'o', 4}, {'u', 5}, {'y', 6}, {'b', 7},
    {'c', 8}, {'d', 9}, {'f', 10}, {'g', 11}, {'h', 12}, {'j', 13}, {'k', 14},
    {'l', 15}, {'m', 16}, {'n', 17}, {'p', 18}, {'q', 19}, {'r', 20},
    {'s', 21}, {'t', 22}, {'v', 23}, {'w', 24}, {'x', 25}, {'z', 26}
};


int LIS(string sequence){ // LIS : Longest Increasing Subsequence
	int N = sequence.size();
	
	// IS_table contains the index of the last element of the Increasing Sequence of each length
	// "IS_table[i]" contains the index "k" of the smallest element "sequence[k]" of the subsequence with a length of "i" ending with "sequence[k]"
	int IS_table[N+1];
	
	// length of the LIS found so far
	int max_length = 0;
	
	for(int i=0; i<N; ++i){
		// Binary search in "IS_table" for the longest subsequence where we can push_back "sequence[i]"
		int beg = 1;
		int end = max_length;
		while( beg <= end ){
			int mid = ceil( ( 1.0*beg + end ) / 2 );
			if(dico[sequence[IS_table[mid]]] < dico[sequence[i]])
				beg = mid+1;
			else
				end = mid-1;
		}
		
		// the length of the longest subsequence ending with "sequence[i]"
		int length = beg;
		
		// update "IS_table"
		IS_table[length] = i;
		
		// update "max_length"
		if(length>max_length)
			max_length = length;
	}
	
	return max_length;
}


int main(){
	string sequence;
	
	cin >> sequence;
	cout << 26-LIS(sequence) << endl;

	return 0;
}
