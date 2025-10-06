//package IntroProblems;

import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.io.BufferedReader;
import java.util.Set;

public class PalindromeReorder {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String str = in.readLine();
        StringBuilder res = new StringBuilder(str);
        int l = 0;
        int r = str.length() - 1;
        Set<String> seen = new HashSet<>();
        for(int i = 0; i < str.length(); i++) {
            String curr = str.charAt(i) + "";
            if(seen.contains(curr)) {
                seen.remove(curr);
                res.replace(l, l+1, curr);
                res.replace(r, r+1, curr);
                l++;
                r--;
                continue;
            }
            seen.add(curr);
        }
        if(seen.size() > 1) {
            System.out.println("NO SOLUTION");
            return;
        }
        for(String s : seen) {
            res.replace(str.length()/2, str.length()/2 + 1, s);
        }
        System.out.println(res);
    }
}
