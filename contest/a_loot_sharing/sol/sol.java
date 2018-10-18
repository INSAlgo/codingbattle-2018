import java.util.Scanner;

public class a_loot_sharing {
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int b = sc.nextInt();
		int t = sc.nextInt();
		int n = sc.nextInt();
		if (2*b + 3*t <= n) {
			System.out.println("LOOT!");
		}
		else{
			System.out.println("RHUM!");
		}
	}
}
