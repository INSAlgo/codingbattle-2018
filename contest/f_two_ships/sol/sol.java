import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class f_two_ships {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int nN, nR;
        int totalWeight = 0;
        int weights[];
        
        nN = sc.nextInt();
        nR = sc.nextInt();
        
        weights = new int[nN];
        for(int i=0; i<nN; i++) {
            weights[i] = sc.nextInt();
            totalWeight += weights[i];
        }
        
        HashMap<Integer, Integer> rivals = new HashMap<Integer, Integer>();
        boolean hasRival[] = new boolean[nN];
        for(int i=0; i<nR; i++) {
            int nID1 = sc.nextInt();
            int nID2 = sc.nextInt();
            rivals.put(Math.min(nID1, nID2), Math.max(nID1, nID2));
            hasRival[nID1] = true;
            hasRival[nID2] = true;
        }
        for(int i=0; i<nN; i++) {
            if(!hasRival[i]) {
                rivals.put(i, -1);
            }
        }
        
        int boatMin = knapsack(totalWeight/2, rivals, weights);
        System.out.println(totalWeight - 2*boatMin);
    }
    
    public static int knapsack(int nW, HashMap<Integer, Integer> rivals, int weights[]) {
        // 2-dimensional DP
    	// L(i, j) <-> if it is possible to have a boat with weight j, considering
    	// only the pirates in the first i couples of rivals
    	boolean L[][] = new boolean[rivals.size() + 1][nW + 1];
    
    	// initialize to false
    	for(int i=0; i <= rivals.size(); i++) {
    		for (int j = 0; j <= nW; j++) {
    			L[i][j] = false;
    		}
    	}
    
    	// L(0, 0) = true
    	// L(0, j) = false for j != 0
    	L[0][0] = true;
    
    	// L(i+1, j) = L(i, j-w[k]) or L(i, j), where k is one of the pirates
    	// concerned by the (i+1)-th rivalry
    	int jWeight = 0; // How many rivalries have been explored
    	for (Map.Entry<Integer, Integer> rivalry : rivals.entrySet()) {
    		for (int j = 0; j <= nW; j++) {
    			if (rivalry.getValue() != -1) {
    				if (j - weights[rivalry.getKey()] >= 0) {
    					L[jWeight + 1][j] = L[jWeight][j - weights[rivalry.getKey()]]
    					                    || L[jWeight + 1][j];
    				}
    				if (j - weights[rivalry.getValue()] >= 0)
    				{
    					L[jWeight + 1][j] = L[jWeight][j - weights[rivalry.getValue()]]
    					                    || L[jWeight + 1][j];
    				}
    			}
    			else {
    				if (j - weights[rivalry.getKey()] >= 0) {
    					L[jWeight + 1][j] = L[jWeight][j - weights[rivalry.getKey()]]
    					                    || L[jWeight][j];
    				}
    				else
    					L[jWeight + 1][j] = L[jWeight][j];
    			}
    		}
    		jWeight++;
    	}
    
    	int nWMax = nW;
    	while ((nWMax >= 0) && (!L[rivals.size()][nWMax])) {
    		nWMax--;
    	}
    
    	return nWMax;
    }
    
}
