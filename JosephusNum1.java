package SearchingAndSorting;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class JosephusNum1 {
    public static class ListNode {
        public int val;
        public ListNode next;
        public ListNode(int val) {
            this.val = val;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) {
            System.out.println(1);
            return;
        }

        LinkedList<Integer> q = new LinkedList<>();
        for(int i = 1; i <= n; i++){
            q.add(i);
        }
        while(!q.isEmpty()) {
            if (q.size() == 1) {
                System.out.print(q.pop());
            } else {
                int first = q.pop();
                int second = q.pop();
                System.out.print(second + " ");
                q.addLast(first);
            }
        }
    }
}
