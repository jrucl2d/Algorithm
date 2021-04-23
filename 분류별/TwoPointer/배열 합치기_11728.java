import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] a, b;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        a = new int[n];
        b = new int[m];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.valueOf(st.nextToken());
        }
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < m; i++) {
            b[i] = Integer.valueOf(st.nextToken());
        }
        int ap = 0, bp = 0;
        StringBuilder sb = new StringBuilder();
        while (ap != n && bp != m) {
            if (a[ap] > b[bp]) {
                sb.append(b[bp++] + " ");
            } else if (a[ap] <= b[bp]) {
                sb.append(a[ap++] + " ");
            }
        }
        if (ap == n) {
            for (int i = bp; i < m; i++) {
                sb.append(b[i] + " ");
            }
        } else if (bp == m) {
            for (int i = ap; i < n; i++) {
                sb.append(a[i] + " ");
            }
        }
        System.out.println(sb);
    }
}
