//package IntroProblems;

import java.util.Scanner;

public class BitStrings {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long res = 1;
        long a = 2;
        long mod = 1000000007;
        while (n > 0) {
            //System.out.println("a: " + a + " --- res: " + res);
            if ((n & 1) == 1) {
                res *= a;
                res %= mod;
            }
            a *= a;
            a %= mod;
            n >>= 1;
        }
        System.out.println(res);
    }
}
