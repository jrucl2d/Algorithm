import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Solution solution = new Solution();
        solution.solution();
    }
    static class Solution {
        int n, m, k, ans = 0;
        int[][] note;
        Info[] arr;
        public void solution() throws IOException {
            input();
            logic();
            System.out.println(ans);
        }
        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            note = new int[n][m];
            arr = new Info[k];
            for (int i = 0; i < k; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int r = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                arr[i] = new Info(r, c);
                for (int a = 0; a < r; a++) {
                    st = new StringTokenizer(br.readLine(), " ");
                    for (int b = 0; b < c; b++) {
                        arr[i].arr[a][b] = Integer.parseInt(st.nextToken());
                        if (arr[i].arr[a][b] == 1) arr[i].cnt += 1;
                    }
                }
            }
        }

        void logic() {
            for (Info sticker : arr) {
                for (int d = 0; d < 4; d++) {
                    if (fit(sticker)) {
                        ans += sticker.cnt;
                        break;
                    }
                    turn(sticker);
                }
            }
        }

        boolean fit(Info sticker) {
            int r = sticker.n;
            int c = sticker.m;
            for (int i = 0; i <= n - r; i++) {
                for (int j = 0; j <= m - c; j++) {
                    if (rightPlace(sticker, i, j, r, c)) {
                        stick(sticker, i, j, r, c);
                        return true;
                    }
                }
            }
            return false;
        }

        void stick(Info sticker, int i, int j, int r, int c) {
            for (int a = i; a < i + r; a++) {
                for (int b = j; b < j + c; b++) {
                    note[a][b] += sticker.arr[a - i][b - j];
                }
            }
        }

        boolean rightPlace(Info sticker, int i, int j, int r, int c) {
            for (int a = i; a < i + r; a++) {
                for (int b = j; b < j + c; b++) {
                    if (sticker.arr[a - i][b - j] == 1 && note[a][b] == 1) return false;
                }
            }
            return true;
        }

        void turn(Info info) {
            int nn = info.m;
            int mm = info.n;
            int[][] narr = new int[nn][mm];
            for (int i = 0; i < info.n; i++) {
                for (int j = 0; j < info.m; j++) {
                    narr[j][info.n - i - 1] = info.arr[i][j];
                }
            }
            info.arr = narr;
            info.n = nn;
            info.m = mm;
        }
        class Info {
            int n, m, cnt;
            int[][] arr;
            public Info (int n, int m) {
                this.n = n;
                this.m = m;
                this.cnt = 0;
                arr = new int[n][m];
            }
        }
    }
}

