/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
// import java.math.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		try{
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            PrintWriter ot=new PrintWriter(System.out);
            int t=Integer.parseInt(br.readLine().trim());
            // int total=0;
            while(t-->0)
            {
                int n=Integer.parseInt(br.readLine().trim());
                String s[]=br.readLine().trim().split(" ");
                // inta a[]=new int[n];
                HashSet<Integer> set=new HashSet<>();
                int neg=0,pos=0;
                for(int i=0;i<n;i++)
                {
                    int temp=Integer.parseInt(s[i]);
                    if(!set.contains(temp))
                    {
                        set.add(temp);
                        if(temp<0)
                        neg+=temp;
                        else
                        pos+=temp;
                    }
                }
                ot.println(pos+" "+neg);
            }
            ot.close();
            br.close();
            
        } catch(Exception e){
            System.err.println("ERROR");
            return;
        }
    }
}
    
