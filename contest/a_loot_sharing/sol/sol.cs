using System;
					
public class Program
{
	public static void Main()
	{
		int b = Convert.ToInt32(Console.ReadLine());
		int t = Convert.ToInt32(Console.ReadLine());
		int n = Convert.ToInt32(Console.ReadLine());
		
		if(2*b+3*t <= n){
			Console.WriteLine("LOOT!\n");
		}else{
			Console.WriteLine("RHUM!\n");
		}
	}
}
