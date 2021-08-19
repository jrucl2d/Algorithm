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
        int n, k, cnt = 1;

        public void solution() throws IOException {
            input();
            StringBuilder sb = new StringBuilder();
            find(0, sb);
            System.out.println(-1);
        }

        void find(int sum, StringBuilder sb) {
            if (sum == n) {
                if (cnt == k) {
                    System.out.println(sb);
                    System.exit(0);
                }
                cnt += 1;
                return;
            }
            for (int i = 1; i <= 3; i++) {
                if (sum + i <= n) {
                    StringBuilder sb2 = new StringBuilder(sb);
                    if (sum == 0) {
                        find(sum + i, sb2.append(i));
                        continue;
                    }
                    find(sum + i, sb2.append('+').append(i));
                }
            }
        }
        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
        }
    }
}

