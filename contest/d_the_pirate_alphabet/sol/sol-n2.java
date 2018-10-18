import java.util.Scanner;
import java.util.Collections; 
import java.util.HashMap;
import java.util.Map;


public class d_the_pirate_alphabet {
    
    public static int LIS(String sequence){
		
		Map<Character, Integer> dico = new HashMap<Character, Integer>() {{
            put('a', 1); put('e', 2); put('i', 3); put('o', 4); 
            put('u', 5); put('y', 6); put('b', 7); put('c', 8); 
            put('d', 9); put('f', 10); put('g', 11); put('h', 12);
            put('j', 13); put('k', 14); put('l', 15); put('m', 16);
            put('n', 17); put('p', 18); put('q', 19); put('r', 20);
            put('s', 21); put('t', 22); put('v', 23); put('w', 24);
            put('x', 25); put('z', 26);
        }};
		
		
		int N = sequence.length();
	
		// "dp[i]" contains the LIS of "sequence[0..i]"
		int[] dp = new int[N];

		// length of the LIS found so far
		int max_length = 0;


		for(int i=0; i<N; ++i){
			dp[i] = 1;
			for(int j=0; j<i; ++j){
				if( dico.get(sequence.charAt(j)) < dico.get(sequence.charAt(i)) ){
					dp[i] = Math.max( dp[i], dp[j]+1 ); 
				}
			}

			max_length = Math.max( max_length, dp[i] );
		}

		return max_length;
	}
	
	
	public static void main(String args[]) {
        Scanner reader = new Scanner(System.in);
        String sequence = reader.nextLine();
        int max_length = LIS(sequence);
        
        System.out.println(26-max_length);
    }
}

