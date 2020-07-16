import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */

        int n=0;
        String s1,sEven,sOdd;

        Scanner scanObj = new Scanner(System.in);
        n=scanObj.nextInt();
        scanObj.nextLine(); //trim \n 
        s1="";
        for(int i =0;i<n;++i)
        {
            s1= scanObj.nextLine();
            sEven="";
            sOdd="";
            for(int j=0;j<s1.length();++j)
            {
                if(j%2==0)
                sEven=sEven+(s1.charAt(j));
                else
                sOdd+=(s1.charAt(j));
            }
            System.out.println(sEven+" "+sOdd);
        }
    }
}