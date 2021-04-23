import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] arr;
    static long ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        int highest = 0;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
            highest = Math.max(highest, arr[i]);
        }
        binary(0, highest);
        System.out.println(ans);
    }

    static void binary(int s, int e) {
        if (s <= e) {
            int mid = (s + e) / 2;
            long sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (arr[i] - mid < 0 ? 0 : arr[i] - mid);
            }
            if (sum < m) {
                binary(s, mid - 1);
                return;
            }
            ans = Math.max(ans, mid);
            binary(mid + 1, e);
        }
    }
}
