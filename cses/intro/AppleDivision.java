//package IntroProblems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AppleDivision {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String ps = br.readLine();
        String[] pList = ps.split(" ");
        int[] pArr = new int[n];
        long total = 0;
        for(int i = 0; i < n; i++) {
            pArr[i] = Integer.parseInt(pList[i]);
            total += pArr[i];
        }
        System.out.println(dfs(0, 0, total, pArr));
    }
    private static long dfs(int i, long curr, long total, int[] pArr) {
        if (i >= pArr.length) {
            return Math.abs(curr-total);
        }
        long minDifference = Math.abs(curr - total);
        long oldDifference = minDifference;
        long newDifference = Math.abs(curr + pArr[i] - (total - pArr[i]));

        if (newDifference < oldDifference) {
            minDifference = Math.min(
                    minDifference,
                    dfs(i+1, curr + pArr[i], total - pArr[i], pArr)
            );
        }
        minDifference = Math.min(minDifference, dfs(i+1, curr, total, pArr));
        return minDifference;
    }

}
