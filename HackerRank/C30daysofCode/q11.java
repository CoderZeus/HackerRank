import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class q11 {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        scanner.close();
        String pattern="";
        int value =0;
        for(int i=n;i>=1;i=i/2)
        { 
             value = i%2;
             pattern+=Integer.toString(value); 

        }

    value =-1;
    int max =0;
    int count =0;
   // System.out.println("Pattern is "+pattern);
    for(int i=0;i<pattern.length();++i)
    {
      if(pattern.charAt(i)=='1')
      {
        ++count;
        //System.out.println("1 found");
      }
      else 
      {
          if(count>max)
           max =count;

          count =0;
          value = i;
      }    

    }
    if(count>max)
           max =count;

     System.out.println(max);

        
    }
}
