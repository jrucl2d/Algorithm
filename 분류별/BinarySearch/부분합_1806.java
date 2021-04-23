import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }

        int s = 0, e = 0, sum = arr[s];
        int ans = Integer.MAX_VALUE;
        while (true) {
            if (e < n && sum < m) {
                e += 1;
                if (e != n)
                    sum += arr[e];
            } else {
                if (sum >= m) {
                    ans = Math.min(ans, (e - s + 1));
                }
                sum -= arr[s];
                s += 1;
                if (s == n)
                    break;
            }
        }
        if (ans == Integer.MAX_VALUE) {
            System.out.println(0);
        } else {
            System.out.println(ans);
        }
    }
}
