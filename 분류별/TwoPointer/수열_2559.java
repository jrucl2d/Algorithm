import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine(), " ");
        int sum = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
            if (i < k)
                sum += arr[i];
        }
        int s = 0, e = k - 1, ans = sum;
        while (e + 1 < n) {
            sum -= arr[s];
            s += 1;
            e += 1;
            sum += arr[e];
            ans = Math.max(sum, ans);
        }
        System.out.println(ans);
    }
}