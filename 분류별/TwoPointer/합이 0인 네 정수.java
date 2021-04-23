import java.io.*;
import java.util.*;

public class Main {
    static final int INF = 4000;
    static int n;
    static long[][] arr;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr = new long[n][4];
        StringTokenizer st;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < 4; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
        int nn = n * n;
        long[] ot = new long[nn];
        int otIndex = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ot[otIndex++] = arr[i][0] + arr[j][1];
            }
        }
        Arrays.sort(ot);
        long[] tf = new long[nn];
        int tfIndex = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tf[tfIndex++] = arr[i][2] + arr[j][3];
            }
        }
        Arrays.sort(tf);
        int s = 0, e = nn - 1;
        long ans = 0;
        while (true) {
            if (s >= nn || e < 0)
                break;
            if (ot[s] + tf[e] == 0) {
                int i = s;
                long first = 0, second = 0;
                while (i < nn && ot[i] + tf[e] == 0) {
                    first += 1;
                    i += 1;
                }
                int j = e;
                while (j >= 0 && ot[s] + tf[j] == 0) {
                    second += 1;
                    j -= 1;
                }
                ans += (first * second);
                s = i;
                e = j;
            } else if (ot[s] + tf[e] < 0)
                s += 1;
            else
                e -= 1;
        }
        System.out.println(ans);
    }
}
