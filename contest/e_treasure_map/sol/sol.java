import java.util.LinkedList;
import java.util.Scanner;

class Bridge {
    public int max_weight;
    public int dst;
}

class Treasure {
    public int weight;
    public LinkedList<Bridge> bridges = new LinkedList<Bridge>();
}

public class e_treasure_map {
	private static int n;
	private static Treasure[] treasures;
	
	// Read input and construct the tree
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		treasures = new Treasure[n];
		sc.nextLine();
		for(int i=0; i<n; i++) {
		    treasures[i] = new Treasure();
		    treasures[i].weight = sc.nextInt();
		}
		sc.nextLine();
		for(int i=0; i<n-1; i++) {
		    int src = sc.nextInt();
		    Bridge b = new Bridge();
		    b.dst = sc.nextInt();
		    b.max_weight = sc.nextInt();
		    treasures[src].bridges.add(b);
		}
		
		System.out.println(DFS(0));
	}
	
	// Recursively get the biggest amount of gold we can get at a given node
	public static int DFS(int node) {
	    int sum = treasures[node].weight;
	    for(Bridge b : treasures[node].bridges) {
	        sum += Math.min(DFS(b.dst), b.max_weight);
	    }
	    return sum;
	}
}
