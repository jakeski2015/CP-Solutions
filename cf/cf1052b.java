import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class cf1052b {
    //find if we can solve this problem with atleast 3 unique solutions
    public static void solve(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); //num of sets
        int m = Integer.parseInt(st.nextToken()); //max value within sets
        int[] counter = new int[m + 1];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int sizeOfSetI = Integer.parseInt(st.nextToken());
            for(int j = 0; j < sizeOfSetI; j++) {
                counter[Integer.parseInt(st.nextToken())]++;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for(int i = 0; i < t; i++) {
            solve(br);
        }
    }
}
