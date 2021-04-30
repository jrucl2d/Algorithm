import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static int[] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int total = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
            total += arr[i];
        }
        k = Integer.valueOf(br.readLine());
        double ans = 0;
        for (int i = 0; i < n; i++) {
            if (k > arr[i]) continue; // 애초에 k개를 뽑을 수 없다.
            double tmp = 1.0;
            // 전체 조약돌 중 i번째 조약돌로만 k개 뽑을 확률
            for (int j = 0; j < k; j++) {
                tmp *= (double) (arr[i] - j) / (total - j);
            }
            ans += tmp;
        }
        System.out.println(String.format("%.15f", ans));
    }
}
