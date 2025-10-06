package IntroProblems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class missingCoinSum {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int[] coins = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(coins);
        long canCreate = 0;
        for (int coin : coins) {
            if (coin - canCreate > 1) {
                System.out.println(canCreate + 1);
                return;
            }
            canCreate += coin;
        }
        System.out.println(canCreate + 1);
    }
}
