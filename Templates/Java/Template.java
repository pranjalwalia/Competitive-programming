package Templates.Java;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Template {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int[] IntInput() throws IOException {
        String s[]= br.readLine().split(" ");
        int len_s=s.length;
        int arr[] = new int[len_s];
        for(int i=0;i<len_s;i++)
            arr[i]=Integer.parseInt(s[i]);

        return arr;
    }

    public static long[] LongInput() throws IOException {
        String s[]= br.readLine().split(" ");
        int len_s=s.length;
        long arr[] = new long[len_s];
        for(int i=0;i<len_s;i++)
            arr[i]=Long.parseLong(s[i]);

        return arr;
    }

    public static int DecimalLength(long n){
        return (int)(Math.floor(Math.log10(n)+1));
    }

    public static int BinaryLength(long n){
        return (int)((Math.floor(Math.log10(n)/Math.log10(2))+1));
    }

    public static void main(String[] args) throws IOException {

        PrintWriter out= new PrintWriter(System.out);

        /***  Code goes Here  ***/
        
        /***  Code Ends Here ***/
        out.close();
    }
}