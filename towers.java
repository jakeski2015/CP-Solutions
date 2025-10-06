package SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;

public class towers {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        int ans = 0;
        int[] blocks = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        TreeMap<Integer, Integer> multiset = new TreeMap<>();
        for (int block : blocks) {
            Map.Entry<Integer, Integer> entry = multiset.higherEntry(block);
            if (entry == null) {
                ans++;
                multiset.put(block, multiset.getOrDefault(block, 0) + 1);
            } else {
                if (entry.getValue() == 1) {
                    multiset.remove(entry.getKey());
                } else {
                    multiset.put(entry.getKey(), entry.getValue() - 1);
                }
                multiset.put(block, multiset.getOrDefault(block, 0) + 1);
            }
        }
        System.out.println(ans);
    }
}
