using System;
// using System.Linq;
// using System.Text;
using System.Collections.Generic;


public class c_riddle
{
    public static int Main(string[] args)
    {
        string l = Console.ReadLine();
        Int32 n = Int32.Parse(Console.ReadLine());

        int [] t = new int[10];
        Dictionary<string, Int32> detCycle = new Dictionary<string, Int32>();
        int i = 0;
        while(i < n){
            i++;
            // Count occurences of every digit in the current number's string
            for(int j = 0 ; j < l.Length ; j++){
                t[int.Parse(l.Substring(j, 1)) - 0] += 1;
            }

            // Create the new number's string
            l = "";
            for(int j = 0 ; j < t.Length ; j++){
                if(t[j] != 0){
                    l += t[j].ToString() + j.ToString();
                    t[j] = 0;
                }
            }

            // Detect cycles
            if (detCycle.ContainsKey(l)){
                // Cycle detected, skip as many steps as possible
                int cycle = i - detCycle[l];
                int toGo = (n - i) / cycle;
                i += toGo * cycle;
            }
            else{
                // No cycle detected, carry on
                detCycle.Add(l, i);
            }
        }
        Console.Write(l);

        return 0;
    }
}
