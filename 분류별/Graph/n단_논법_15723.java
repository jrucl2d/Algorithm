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
        int n, m;
        int[] arr = new int[27];
        StringBuilder ans = new StringBuilder();

        public void solution() throws IOException {
            input();
            System.out.println(ans);
        }

        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            for (int i = 0; i < 27; i++) arr[i] = -1;
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                char first = st.nextToken().charAt(0);
                st.nextToken();
                char second = st.nextToken().charAt(0);
                arr[first - 'a'] = second - 'a';
            }
            m = Integer.parseInt(br.readLine());
            for (int i = 0; i < m; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                char first = st.nextToken().charAt(0);
                st.nextToken();
                char second = st.nextToken().charAt(0);
                if (logic(first, second)) ans.append("T\n");
                else ans.append("F\n");
            }
        }
        boolean logic(char a, char b) {
            int first = a - 'a';
            int second = b - 'a';
            int now = first;
            while (true) {
                if (now == -1) break;
                if (now == second) return true;
                now = arr[now];
            }
            return false;
        }
    }
}

