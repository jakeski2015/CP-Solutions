package SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class collectingNumbers {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int i = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashMap<Integer,Integer> nums = new HashMap<>();
        while (i < n) {
            nums.put(Integer.parseInt(st.nextToken()), i);
            i++;
        }
        i = 1;
        int prev = -1;
        int passes = 1;
        while (i <= n) {
            int curr = nums.get(i);
            if (curr <= prev) {
                passes++;
                prev = -1;
                continue;
            }
            prev = curr;
            i++;
        }
        System.out.println(passes);
    }
}