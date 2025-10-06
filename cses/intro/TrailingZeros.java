//package IntroProblems;

import java.util.Scanner;

public class TrailingZeros {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        
        //calculate nfact

        long nfact = n;
        long place = 10;
        int res = 0;
        while (nfact%place == 0) {
            res += 1;
            place *= 10;
        }
        System.out.println(res);
    }
}
