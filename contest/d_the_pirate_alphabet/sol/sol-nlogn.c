#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LENGTH 100002


int isLessThan(char c1, char c2){ // alphabet comparator
	int isVowel1 = (c1=='a') || (c1=='e') || (c1=='i') || (c1=='o') || (c1=='u') || (c1=='y');
	int isVowel2 = (c2=='a') || (c2=='e') || (c2=='i') || (c2=='o') || (c2=='u') || (c2=='y');

	if(isVowel1 && !isVowel2)
		return 1;
	else if(!isVowel1 && isVowel2)
		return 0;
	else
		return c1<c2;
}


int LIS(char sequence[], int N){
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
			if( isLessThan(sequence[IS_table[mid]], sequence[i]) )
				beg = mid + 1;
			else
				end = mid - 1;
		}
		
		// the length of the longest subsequence ending with "sequence[i]"
		int length = beg;
		
		// update "IS_table"
		IS_table[length] = i;
		
		// update "max_length"
		if(length>max_length)
			max_length=length;
	}
	
	return max_length;
}


int main(){
	char sequence[MAX_LENGTH];
	
	scanf("%s", sequence);
	int sequence_len = strlen(sequence);
	
	printf("%d\n", 26-LIS(sequence, sequence_len));

	return 0;
}
