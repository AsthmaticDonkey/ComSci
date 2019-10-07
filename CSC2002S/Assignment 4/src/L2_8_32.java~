import java.util.*;
import java.io.*;

public class L2_8_32
{
	public static void main(String [] args)
	{
		try{Scanner sc = new Scanner(new File(args[0]+".addr"));
		int[] tag1 = new int[8];
		int[] tag2 = new int[64]; 
		int hex1, hex2;
		int hex3, hex4;
		int cycles, hit1, miss1;
		int hit2, miss2;
		miss1 = 0;
		miss2 = 0;
		hit1 = 0;
		hit2 = 0;		
		cycles = 0;
		
		for(int i=1000; i<1008; i++)
		{
			tag1[i-1000] = i;
		}
		for(int i=1000; i<1064; i++)
		{
			tag2[i-1000] = i;
		}

		while(sc.hasNextLine())
		{

			hex1 = Integer.parseInt((sc.nextLine()).trim(), 16);
			hex3 = hex1;			
			hex1 = hex1/32;			
			hex2 = hex1%8;
			hex1 = hex1/8;

			hex3 = hex3/64;			
			hex4 = hex3%64;
			hex3 = hex3/64;

			if(tag1[hex2] == hex1)
			{
				cycles += 10;
				hit1 += 1;
			}
			else if(tag2[hex4] == hex3)
			{
				cycles += 100;
				hit2 += 1;
				miss1 += 1;
				tag1[hex2] = hex1;
			}
			else
			{
				cycles += 1000;
				miss2 += 1;
				miss1 += 1;
				tag1[hex2] = hex1;
				tag2[hex4] = hex3;			
			}
		}
		System.out.println("L1 hits:    "+hit1);
		System.out.println("L1 misses:  "+miss1);
		System.out.println("L2 hits:    "+hit2);
		System.out.println("L2 misses:  "+miss2);
		System.out.println("Cycles:     "+cycles);
		}
		catch(FileNotFoundException e){}
	}
}
