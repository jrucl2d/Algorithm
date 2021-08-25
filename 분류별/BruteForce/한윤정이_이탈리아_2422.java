import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Solution solution = new Solution();
        solution.solution();
    }
    static class Solution {
        int n, m, ans = 0;
        boolean[][] no;

        public void solution() throws IOException {
            input();
            func();
            System.out.println(ans);
        }

        void func() {
            List<Integer> list = new ArrayList<>();
            dfs(list, 1);
        }

        void dfs(List<Integer> list, int now) {
            if (list.size() == 3) {
                ans += 1;
                return;
            }
            for (int i = now; i <= n; i++) {
                boolean can = true;
                for (int j = 0; j < list.size(); j++) {
                    int inner = list.get(j);
                    if (no[inner][i]) {
                        can = false;
                        break;
                    }
                }
                if (!can) continue;
                list.add(i);
                dfs(list, i + 1);
                list.remove(list.size() - 1);
            }
        }

        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            no = new boolean[n + 1][n + 1];
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                no[a][b] = no[b][a] = true;
            }
        }
    }
}

