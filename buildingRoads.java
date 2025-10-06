package Graphs;

import java.io.*;
import java.util.*;

public class buildingRoads {
    static HashMap<Integer, List<Integer>> adj = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\jakes\\IdeaProjects\\CodingProblems\\src\\in.txt"));
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new FileWriter("C:\\Users\\jakes\\IdeaProjects\\CodingProblems\\src\\out.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for(int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            if (adj.containsKey(u)) {
                adj.get(u).add(v);
            } else {
                adj.put(u, new ArrayList<Integer>());
                adj.get(u).add(v);
            }
            if (adj.containsKey(v)) {
                adj.get(v).add(u);
            } else {
                adj.put(v, new ArrayList<Integer>());
                adj.get(v).add(u);
            }
        }
        HashSet<Integer> seen = new HashSet<>();
        ArrayList<Integer> roots = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (!seen.contains(i)) {
                roots.add(i);
                seen.add(i);
                LinkedList<Integer> q = new LinkedList<>();
                q.add(i);
                while (!q.isEmpty()) {
                    int u = q.removeFirst();
                    if (adj.containsKey(u)) {
                        for (int v : adj.get(u)) {
                            if (!seen.contains(v)) {
                                seen.add(v);
                                q.add(v);
                            }
                        }
                    }
                }
            }
        }
        pw.println(roots.size() - 1);
        for(int i = 0; i < roots.size() - 1; i++) {
            pw.println(roots.get(i) + " " + roots.get(i+1));
        }
    }
}
