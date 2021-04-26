import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
        int s = 0, e = 0;
        int sum = arr[0];
        int ans = 0;
        while (e < n) {
            if (sum == m) {
                ans += 1;
                e += 1;
                if (e == n)
                    break;
                sum += arr[e];
                sum -= arr[s];
                s += 1;
                continue;
            }
            if (sum < m) {
                e += 1;
                if (e == n)
                    break;
                sum += arr[e];
                continue;
            }
            sum -= arr[s];
            s += 1;
        }
        System.out.println(ans);
    }
}