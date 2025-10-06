//package IntroProblems;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class GrayCode {

    public static List<String> dfs(int n) {
        if (n == 1) {
            ArrayList<String> curr = new ArrayList<String>();
            curr.add("0");
            curr.add("1");
            return curr;
        }
        List<String> prev = dfs(n - 1);
        ArrayList<String> curr = new ArrayList<String>();
        for(int i = 0; i < prev.size(); i++) {
            curr.add("0" + prev.get(i));
        }
        for(int i = prev.size() - 1; i >= 0; i--) {
            curr.add("1" + prev.get(i));
        }
        return curr;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        for(String s : dfs(N)) {
            System.out.println(s);
        }
    }
}
