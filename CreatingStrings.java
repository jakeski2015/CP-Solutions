//package IntroProblems;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class CreatingStrings {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        int[] counter = new int[26];
        for(char c : line.toCharArray()) {
            counter[(int)c - (int)'a'] += 1;
        }
        HashSet<String> results = new HashSet<>();
        dfs("", counter, results);
        ArrayList<String> resultsList = new ArrayList<>(results);
        Collections.sort(resultsList);
        System.out.println(resultsList.size());
        for(String result : resultsList) {
            System.out.println(result);
        }


    }
    private static void dfs(String s, int[] counter, HashSet<String> results) {
        if (Arrays.equals(counter, new int[26])) {
            results.add(s);
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (counter[i] > 0) {
                String ns = s + (char)((int)'a' + i);
                counter[i] -= 1;
                dfs(ns, counter, results);
                counter[i] += 1;
            }
        }
    }

}
