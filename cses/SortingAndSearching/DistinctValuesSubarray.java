package SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;

public class DistinctValuesSubarray {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        HashSet<Integer> window = new HashSet<>();
        int r = 0;
        long sol = 0;
        for (int l = 0; l < n; l++) {
            while(r < n && !window.contains(arr[r])) {
                window.add(arr[r]);
                r++;
            }
            sol += (r-l);
            window.remove(arr[l]);
        }
        System.out.println(sol);
    }
}
