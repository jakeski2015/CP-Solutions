import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class cf492B {
    static int[] a;
    static int n;
    static int l;

    public static boolean checkStreet(double d) {
        double prev = 0;
        for(int ai : a) {
            if (ai - d > prev) {
                return false;
            }
            prev = ai + d;
        }
        return prev >= l;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        a = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        double maxDist = 0;
        for(int i = 0; i < n - 1; i++) {
            maxDist = Math.max(Math.abs(a[i] - a[i+1]), maxDist);
        }
        Arrays.sort(a);
        double left = 0;
        double right = l;
        while (right - left > Math.pow(10, -9)) {
            double middle = left + (right - left)/2;
            if (checkStreet(middle)) {
                right = middle;
            } else {
                left = middle;
            }
        }
        System.out.println(left);
    }
}
