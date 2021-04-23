import java.io.*;
import java.util.*;

public class Main {
    static final long INF = 1000000000;
    static long x, y, first, ans = INF + 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        x = Integer.valueOf(st.nextToken());
        y = Integer.valueOf(st.nextToken());
        first = getPercent(x, y);
        if (first >= 99) {
            System.out.println(-1);
            return;
        }
        binary(1, INF);
        System.out.println(ans);
    }

    static void binary(long s, long e) {
        if (s <= e) {
            long mid = (s + e) / 2;
            long nx = x + mid, ny = y + mid;
            long nper = getPercent(nx, ny);
            if (nper > first) {
                ans = Math.min(ans, mid);
                binary(s, mid - 1);
                return;
            }
            binary(mid + 1, e);
        }
    }

    static long getPercent(long x, long y) {
        return (y * 100) / x;
    }
}
