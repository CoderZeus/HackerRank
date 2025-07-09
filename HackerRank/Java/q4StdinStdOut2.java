package HackerRank.Java;

import java.io.*;
import java.util.*;

public class q4StdinStdOut2 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner(System.in);
        int intNum = scanner.nextInt();
        scanner.nextLine();
        double doubleNum = scanner.nextDouble();
        scanner.nextLine();
        String stringOutput = scanner.nextLine();
        
        System.out.println("String: " + stringOutput);
        System.out.println("Double: " + doubleNum);
        System.out.println("Int: " + intNum);
        
    }
}