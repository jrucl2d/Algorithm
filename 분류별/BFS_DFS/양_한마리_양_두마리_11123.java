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
        int t, n, m, index = 0;
        char[][] arr;
        int[] ans;
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};
        public void solution() throws IOException {
            input();
            for (int i = 0; i < index; i++) {
                System.out.println(ans[i]);
            }
        }
        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            t = Integer.parseInt(br.readLine());
            ans = new int[t];
            for (int i = 0; i < t; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                n = Integer.parseInt(st.nextToken());
                m = Integer.parseInt(st.nextToken());
                arr = new char[n][m];
                for (int j = 0; j < n; j++) {
                    String tmp = br.readLine();
                    for(int k = 0; k < m; k++) {
                        arr[j][k] = tmp.charAt(k);
                    }
                }
                logic();
            }
        }
        void logic() {
            int inner = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] != '#') continue;
                    inner += 1;
                    dfs(i, j);
                }
            }
            ans[index++] = inner;
        }

        void dfs(int i, int j) {
            arr[i][j] = '.';
            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d], ny = j + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (arr[nx][ny] != '#') continue;
                dfs(nx, ny);
            }
        }
    }
}

