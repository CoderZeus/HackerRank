
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;


class Difference {
  	private int[] elements;
  	public int maximumDifference;

	public Difference(int [] data)
    {
        elements = new int[data.length];
        elements = data;
    } // Add your code here

    public void computeDifference()
    {
        int maxValue=0;
        int minValue=0;
        for (int i =0;i< elements.length;++i)
        {
           if(elements[i]>elements[maxValue])
            maxValue = i;

           else if (elements[i]<elements[minValue])
            minValue = i;
        }

        maximumDifference = elements[maxValue]-elements[minValue];
    }

} // End of Difference class

public class q15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        Difference difference = new Difference(a);

        difference.computeDifference();

        System.out.print(difference.maximumDifference);
    }
    
}