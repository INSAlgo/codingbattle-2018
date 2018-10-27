#include <iostream>
#include <cmath>
#include <string>
#include <map>

using namespace std;





std::map<char, int> dico = {
    { 'a', 1 },
    { 'e', 2 },
    { 'i', 3 },
    { 'o', 4 },
    { 'u', 5 },
    { 'y', 6 },
    { 'b', 7 },
    { 'c', 8 },
    { 'd', 9 },
    { 'f', 10 },
    { 'g', 11 },
    { 'h', 12 },
    { 'j', 13 },
    { 'k', 14 },
    { 'l', 15 },
    { 'm', 16 },
    { 'n', 17 },
    { 'p', 18 },
    { 'q', 19 },
    { 'r', 20 },
    { 's', 21 },
    { 't', 22 },
    { 'v', 23 },
    { 'w', 24 },
    { 'x', 25 },
    { 'z', 26 }
};





int LIS(string sequence){ // LIS : Longest Increasing Subsequence
	int N = sequence.size();
	
	// "dp[i]" contains the LIS of "sequence[0..i]"
	int dp[N];
	
	// length of the LIS found so far
	int max_length = 0;
	
	
	for(int i=0; i<N; ++i){
		dp[i] = 1;
		for(int j=0; j<i; ++j){
			if( dico[sequence[j]] < dico[sequence[i]] ){
				dp[i] = max( dp[i], dp[j]+1 ); 
			}
		}
		
		max_length = max( max_length, dp[i] );
	}
	
	
	return max_length;
}





int main(){
	string sequence;
	
	cin >> sequence;
	cout << 26-LIS(sequence) << endl;

	return 0;
}



