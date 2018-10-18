using System;
using System.Collections.Generic;
					
public class Program
{
	
	public static int LIS(string sequence){
		Dictionary<char, int> dico = new Dictionary<char, int>{
            { 'a', 1 }, { 'e', 2 }, { 'i', 3 }, { 'o', 4 }, { 'u', 5 },
            { 'y', 6 }, { 'b', 7 }, { 'c', 8 }, { 'd', 9 }, { 'f', 10 },
            { 'g', 11 }, { 'h', 12 }, { 'j', 13 }, { 'k', 14 }, { 'l', 15 },
            { 'm', 16 }, { 'n', 17 }, { 'p', 18 }, { 'q', 19 }, { 'r', 20 },
            { 's', 21 }, { 't', 22 }, { 'v', 23 }, { 'w', 24 }, { 'x', 25 },
            { 'z', 26 }
        };
		
		
		int N = sequence.Length;
	
		// "dp[i]" contains the LIS of "sequence[0..i]"
		int[] dp = new int[N];

		// length of the LIS found so far
		int max_length = 0;


		for(int i=0; i<N; ++i){
			dp[i] = 1;
			for(int j=0; j<i; ++j){
				if( dico[sequence[j]] < dico[sequence[i]] ){
					dp[i] = Math.Max( dp[i], dp[j]+1 ); 
				}
			}

			max_length = Math.Max( max_length, dp[i] );
		}

		return max_length;
	}
	
	public static void Main(){
		string sequence = Console.ReadLine();
		int max_length = LIS(sequence);
		Console.WriteLine(26-max_length);
	}
}
