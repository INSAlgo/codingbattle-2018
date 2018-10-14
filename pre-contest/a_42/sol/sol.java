import java.util.Scanner;

public class a_42{
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		if(n < 42)
			System.out.println("More");
		else if(n > 42)
			System.out.println("Less");
		else
			System.out.println("Bingo!");
	}
}
