import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p16927 {
    static int n, m, r;
    static int[][] arr;

    public static void main(String[] args) throws IOException {
        input();
        int rs = 0, re = n - 1, cs = 0, ce = m - 1;
        while (rs <= re && cs <= ce) {
            int border_size = (re - rs + 1) * 2 + (ce - cs + 1) * 2 - 4;
            int iter_size = r % border_size;
            sol(rs, re, cs, ce, iter_size);
            rs++;
            re--;
            cs++;
            ce--;
        }
        print();
    }

    static void input() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String line = bf.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        r = Integer.valueOf(st.nextToken());
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            line = bf.readLine();
            st = new StringTokenizer(line, " ");
            int j = 0;
            while (st.hasMoreTokens()) {
                arr[i][j++] = Integer.valueOf(st.nextToken());
            }
        }
    }

    static void sol(int rs, int re, int cs, int ce, int iter_cnt) {
        for (int c = 0; c < iter_cnt; c++) {
            int first = arr[rs][cs];
            for (int j = cs; j < ce; j++) {
                arr[rs][j] = arr[rs][j + 1];
            }
            for (int i = rs; i < re; i++) {
                arr[i][ce] = arr[i + 1][ce];
            }
            for (int j = ce; j > cs; j--) {
                arr[re][j] = arr[re][j - 1];
            }
            for (int i = re; i > rs; i--) {
                arr[i][cs] = arr[i - 1][cs];
            }
            arr[rs + 1][cs] = first;
        }
    }

    static void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
