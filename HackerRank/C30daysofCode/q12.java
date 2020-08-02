import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] arr = new int[6][6];

        for (int i = 0; i < 6; i++) {
            String[] arrRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 6; j++) {
                int arrItem = Integer.parseInt(arrRowItems[j]);
                arr[i][j] = arrItem;
            }
        }
        int sum =0;
        int maxSum=0;
        boolean isInitialised = false;
       for (int x = 0; x < 4; ++x )
        {
            for(int y = 0; y < 4; ++y )
                {
                  sum =0;
                  for(int z=0;z<3;++z)
                    {
                        for(int a=0;a<3;++a)
                        {
                            if((x+z<6 )&&(y+a<6))
                            {
                                //System.out.print(arr[x+z][y+a]+" ");
                                if(z==1)
                                {
                                if((a==1))
                                {
                                  sum = sum+arr[x+z][y+a];
                                }
                                }                            
                                else
                                {
                              sum = sum+arr[x+z][y+a];
                                }
                            }
                              
                        }
                        //System.out.println("");
                       
                    }
                   // System.out.println(" x y "+x+y+ "SUM "+sum);


                    if((sum>maxSum)||(!isInitialised))
                    { 
                        isInitialised = true;
                        maxSum= sum;
                       // sum =0;
                       // System.out.println(" x y "+x+y+ "SUM "+maxSum);
                    }
                 }                        
            }
            System.out.println(maxSum);

         // System.out.println(arr[0][0]);
         // System.out.println(arr[4][2]);
         // System.out.println(arr[1][5]);
        scanner.close();
    }
}

