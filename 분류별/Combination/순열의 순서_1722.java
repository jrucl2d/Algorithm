import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static long[] fac = new long[21];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int num = Integer.valueOf(st.nextToken());
        if (num == 1) {
            long k = Long.valueOf(st.nextToken());
            System.out.println(one(k));

        } else {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.valueOf(st.nextToken());
            }
            System.out.println(two(arr));
        }
    }
    static StringBuilder one(long k) {
        StringBuilder sb = new StringBuilder();
        boolean[] numbers = new boolean[21];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                if (numbers[j]) continue;
                // 현재 숫자 제외한 나머지 숫자들을 사용한 순열들의 개수
                long slice = factorial(n - i - 1);
                if (slice < k) { k -= slice; continue; }
                sb.append(j + " ");
                numbers[j] = true;
                break;
            }
        }
        return sb;
    }
    static long two(int[] arr) {
        long ans = 0;
        boolean[] numbers = new boolean[21];
        for (int i = 0; i < n; i++) {
            for (int j = 1; j<= n; j++) {
                if (numbers[j]) continue;
                long slice = factorial(n - i - 1);
                if (j != arr[i]) {
                    ans += slice;
                    continue;
                }
                numbers[j] = true;
                break;
            }
        }
        return ans + 1;
    }
    static long factorial(int now) {
        if (now == 1 || now == 0) {
            fac[1] = 1;
            return 1;
        }
        if (fac[now] != 0) return fac[now];
        fac[now] = now * factorial(now - 1);
        return fac[now];
    }
}
