import java.util.Arrays;
import java.util.Scanner;

public class c_sea_storm {
	private static int[] pos;
	private static int[] hats;
	private static int l;
	private static int n;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		l = sc.nextInt();
		n = sc.nextInt();
		sc.nextLine();
		pos = new int[n];
		for(int i=0; i<n; i++) {
			pos[i] = sc.nextInt();
		}
		sc.nextLine();
		hats = new int[n];
		for(int i=0; i<n; i++){
			hats[i] = sc.nextInt();
		}
		sc.nextLine();
		Arrays.sort(hats);
		boolean[] state = new boolean[n];
		if (backtrack(state, 1, 0)) {
		    System.out.println("YES");
		}
		else {
		    System.out.println("NO");
		}
	}
	
	public static boolean backtrack(boolean[] state, int last_covered_pos, int current_pos_index){
        if(current_pos_index == n) {
            if(last_covered_pos >= l) {
                return true;
            }
            return false;
        }
        
    	    // find the widest hat we haven't placed yet
        int max_hat = 0;
        for(int i=0; i<n; ++i) {
            if(state[i] == false && hats[i] > max_hat) {
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
            if(state[i] == false) {
                // if placing the current hat here can lead to a solution
                if(pos[current_pos_index] - hats[i] - 1 <= last_covered_pos) {
                    // push the current hat here and recurse to the next position
                    state[i] = true;
                    if(backtrack(state, Math.max(pos[current_pos_index] + hats[i], last_covered_pos), current_pos_index + 1)) {
                        // a solution was found !
                        return true;
                    }
                    // pop back the current hat before we evaluate the other hats
                    state[i] = false;
                }
            }
        }
        return false;
	}

}
