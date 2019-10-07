import java.util.*;
import java.io.*;

public class L1_16_32
{
	public static void main(String [] args)
	{
		try{Scanner sc = new Scanner(new File(args[0]+".addr"));
		int[] tag = new int[16]; 
		int hex1, rem, hex2;
		int cycles, hit, miss;
		miss = 1;
		hit = 0;
		cycles = 1000;
		
		for(int i=1000; i<1016; i++)
		{
			tag[i-1000] = i;
		}

		hex1 = Integer.parseInt((sc.nextLine()).trim(), 16);
		hex1 = hex1/32;
		hex2 = hex1%16;
		hex1 = hex1/16;
		tag[hex2] = hex1;
		while(sc.hasNextLine())
		{
			if(tag[hex2] == hex1)
			{
				cycles += 10;
				hit += 1;
			}
			else
			{
				cycles += 1000;
				miss += 1;
				tag[hex2] = hex1;
			}
			hex1 = Integer.parseInt((sc.nextLine()).trim(), 16);
			hex1 = hex1/32;			
			hex2 = hex1%16;
			hex1 = hex1/16;
		}
		System.out.println("L1 hits:    "+hit);
		System.out.println("L1 misses:  "+miss);
		System.out.println("Cycles:     "+cycles);
		}
		catch(FileNotFoundException e){}
	}
}
