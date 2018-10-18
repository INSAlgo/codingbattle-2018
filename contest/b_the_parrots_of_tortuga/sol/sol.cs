using System;

public class b_the_parrots_of_tortuga
{
    public static void Main()
    {
        int nb_parrots;
        int best_offer = 0;
        String seller = "";
        
        String[] parts = Console.ReadLine().Split();
        int g = Convert.ToInt32(parts[0]);
        int n = Convert.ToInt32(parts[1]);
        
        // Go through all trainers in the given order
        for(int i = 0; i < n; ++i){
            parts = Console.ReadLine().Split();
            String name = parts[0];
            int p = Convert.ToInt32(parts[1]);
            int c = Convert.ToInt32(parts[2]);
            
            // Compute how many parrots we can buy from this trainer
            nb_parrots = (int)Math.Floor((double)((g - c) / p));

            // Check if it's better than the best encountered yet
            if( nb_parrots > best_offer ){
                best_offer = nb_parrots;
                seller = name;
            }
        }
        
        if(best_offer == 0){
            Console.WriteLine("Impossible");
        }else{
            Console.WriteLine(best_offer);
            Console.WriteLine(seller);
        }
        
    }
}