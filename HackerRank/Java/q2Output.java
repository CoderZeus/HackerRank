package HackerRank.Java;

import java.io.*;
import java.util.*;

public class q2Output {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner(System.in);
    
        for (int i=0;i < 3 ; ++i){
            int myInt = scanner.nextInt();
            System.out.println(myInt);
        }
        
        scanner.close();
    }
}
