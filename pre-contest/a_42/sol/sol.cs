using System;

class a_42 {
    public static void Main() 
    {
        string Nstr = Console.ReadLine();
        int N = int.Parse(Nstr);
        
        if (N < 42)
            Console.Write("More");
        else if (N > 42)
            Console.Write("Less");
        else if (N == 42)
            Console.Write("Bingo!");
    }
}
