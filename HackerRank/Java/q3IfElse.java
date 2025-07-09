package HackerRank.Java;

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



public class q3IfElse {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(bufferedReader.readLine().trim());
        bufferedReader.close();
        System.out.println(N %2 == 0 ? evaluateEven(N) : "Weird");
    }
    
    private static String evaluateEven(int n) {
        if (n >=2 && n<= 5) {
            return "Not Weird";
        } else if (n >=6  && n<=20) {
            return "Weird";
        } else {
            return "Not Weird";
        }
    }
}

