import java.io.*;
import java.util.*;

public class p17779 {
    static int n;
    static int[][] arr;
    static int[][] show;
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        input();
        for (int d1 = 1; d1 <= n; d1++) {
            for (int d2 = 1; d2 <= n; d2++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (i + d1 + d2 > n) continue;
                        if (j - d1 < 1) continue;
                        if (j + d2 > n) continue;
                        show = new int[n + 1][n + 1];
                        sol(i, j, d1, d2);
                    }
                }
            }
        }
        System.out.println(ans);
    }
    static void innerSol(int x, int y, int d1, int d2) {
        for (int i = 0; i <= d1; i++) {
            show[x + i][y - i] = 5;
            show[x + d2 + i][y + d2 - i] = 5;
        }
        for (int i = 0; i <= d2; i++) {
            show[x + i][y + i] = 5;
            show[x + d1 + i][y - d1 + i] = 5;
        }
    }
    static void sol(int x, int y, int d1, int d2) {
        innerSol(x, y, d1, d2);
        int one = 0, two = 0, three = 0, four = 0, five = 0;
        for (int i = 1; i <= n; i++) {
            boolean five_meet = false;
            for (int j = 1; j <= n; j++) {
                if ((i == x && j == y) || (i == x + d1 + d2 && j == y + d2 - d1)) {
                    five += arr[i][j];
                    show[i][j] = 5;
                }
                else if (show[i][j] == 5) {
                    if (!five_meet) {
                        five_meet = true;
                        five += arr[i][j];
                        show[i][j] = 5;
                    } else {
                        five_meet = false;
                        five += arr[i][j];
                        show[i][j] = 5;
                    }
                }
                else if (five_meet) {
                    five += arr[i][j];
                    show[i][j] = 5;
                } else if (1 <= i && i < x + d1 && 1 <= j && j <= y) {
                    one += arr[i][j];
                } else if (1 <= i && i <= x + d2 && y < j && j <= n) {
                    two += arr[i][j];
                } else if (x + d1 <= i && i <= n && 1 <= j && j < y - d1 + d2) {
                    three += arr[i][j];
                } else if (x + d2 < i && i <= n && y - d1 + d2 <= j && j <= n) {
                    four += arr[i][j];
                }
            }
        }
        int inner_max = Math.max(Math.max(Math.max(Math.max(one, two), three), four), five);
        int inner_min = Math.min(Math.min(Math.min(Math.min(one, two), three), four), five);
        ans = Math.min(ans, inner_max - inner_min);
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        arr = new int[n + 1][n + 1];
        StringTokenizer st;
        for (int i = 1; i < n + 1; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 1; j < n + 1; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
    }
}
