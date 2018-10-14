import java.util.Scanner;
import java.util.HashMap;

public class c_riddle{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		String l = sc.nextLine();
		int n = sc.nextInt();
		int [] t = new int[10];
		HashMap<String,Integer> detCycle = new HashMap<String,Integer>();
		int i = 0;
		while(i < n){
			i++;
			// Count occurences of every digit in the current number's string
			for(int j = 0 ; j < l.length() ; j++){
				t[(int)(l.charAt(j)) - (int)('0')] += 1;
			}

			// Create the new number's string
			l = "";
			for(int j = 0 ; j < t.length ; j++){
				if(t[j] != 0){
					l += String.valueOf(t[j]) + String.valueOf(j);
					t[j] = 0;
				}
			}

			// Detect cycles
			if (detCycle.containsKey(l)){
				// Cycle detected, skip as many steps as possible
				int cycle = i - detCycle.get(l);
				int toGo = (int)((n - i) / cycle);
				i += toGo * cycle;
			}
			else{
				// No cycle detected, carry on
				detCycle.put(l, i);
			}
		}
		System.out.println(l);
	}
}
