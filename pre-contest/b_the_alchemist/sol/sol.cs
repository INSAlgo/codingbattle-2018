using System;

class b_the_alchemist {
    public static void Main() 
    {
        var input = Console.ReadLine();
        var inputParts = input.Split(' ');
        int p = int.Parse(inputParts[0]);
        int l = int.Parse(inputParts[1]);
        int g = int.Parse(inputParts[2]);
        
        int cpt = 0;
        for(int x = 0; x <= p && x*x <= g; x++) {
            for(int y=0; y < l; y++){
                int r = x*x + x*y + y;
                if(r == g) {
                    cpt++;
                }
                else if(r > g) {
                    break;
                }
            }
        }
        
        Console.Write(cpt);
    }
}
