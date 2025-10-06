package SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;

public class playlist {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int l = 0; int r = 0;
        HashSet<Integer> seen = new HashSet<>();
        int overallMax = 0;
        while (l < arr.length && r < arr.length) {
            if (!seen.contains(arr[r])) {
                //System.out.println("l " + l + ", r " + r);
                seen.add(arr[r]);
                if (r - l + 1 > overallMax) {
                    overallMax = r - l + 1;
                }
                r++;
            } else {
                seen.remove(arr[l]);
                l++;
            }
        }
        System.out.println(overallMax);
    }
}
