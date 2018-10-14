import java.util.Scanner;

public class b_the_alchemist {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int p = sc.nextInt();
		int l = sc.nextInt();
		int g = sc.nextInt();
		int cpt = 0;
		for(int x = 0; x <= p && x*x <= g; x++) {
			for(int y = 0; y < l; y++){
				int r = x*x + x*y + y;
				if(r == g) {
					cpt++;
				}
				else if(r > g) {
					break;
				}
			}
		}
		System.out.println(cpt);
	}
}
