import java.util.Scanner;

public class b_the_parrots_of_tortuga {
	public static void main(String [] args){
		Scanner sc = new Scanner(System.in);

		String [] s = sc.nextLine().split(" ");
		int g = Integer.parseInt(s[0]);
		int n = Integer.parseInt(s[1]);
		String seller = "";
		int bestOffer = 0;

		// Go through all trainers in the given order
		for(int i=0;i<n;i++)
		{
			String [] line = sc.nextLine().split(" ");
			String name = line[0];
			int p = Integer.parseInt(line[1]);
			int c = Integer.parseInt(line[2]);

			// Compute how many parrots we can buy from this trainer
			int nb_parrots = (int)((g - c) / p);

			// Check if it's better than the best encountered yet
			if(nb_parrots > bestOffer){
				bestOffer = nb_parrots;
				seller = name;
			}
		}
		if (bestOffer != 0) {
			System.out.println(bestOffer);
			System.out.println(seller);
		}
		else{
			System.out.println("Impossible");
		}
	}
}

