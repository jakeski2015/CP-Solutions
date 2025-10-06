package SearchingAndSorting;

import java.io.*;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class TrafficLights {
    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br = new BufferedReader(new FileReader("C:\\Users\\jakes\\IdeaProjects\\CodingProblems\\src\\in.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("C:\\Users\\jakes\\IdeaProjects\\CodingProblems\\src\\out.txt"));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        TreeSet<Integer> lights = new TreeSet<>();
        TreeMap<Integer, Integer> gaps = new TreeMap<>();
        gaps.put(x, 1);

        while(st.hasMoreTokens()) {
            int light = Integer.parseInt(st.nextToken());
            var lower = lights.lower(light);
            var upper = lights.higher(light);
            int l = lower != null ? lower : 0;
            int u = upper != null ? upper : x;
            int oldGap = u - l;
            gaps.put(oldGap, gaps.get(oldGap) - 1); //decrement oldGap because we are splitting it
            if (gaps.get(oldGap) == 0) {
                gaps.remove(oldGap);
            }
            int lGap = light - l;
            int rGap = u - light;
            if (!gaps.containsKey(lGap)) {
                gaps.put(lGap, 0);
            }
            if (!gaps.containsKey(rGap)) {
                gaps.put(rGap, 0);
            }
            gaps.put(lGap, gaps.get(lGap) + 1);
            gaps.put(rGap, gaps.get(rGap) + 1);

            lights.add(light);
            pw.print(gaps.lastKey() + " ");
        }
        pw.println();
    }
}
