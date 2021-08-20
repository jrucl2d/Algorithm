import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Solution solution = new Solution();
        solution.solution();
    }
    static class Solution {
        int n, m, k;
        int[] want;
        int[] parent;

        public void solution() throws IOException {
            input();
            func();
        }

        void func() {
            Set<Integer> set = new HashSet<>();
            for (int i = 1; i <= n; i++) {
                set.add(parent[i]);
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                int p = findP(i);
                if (p != 0) {
                    ans += want[p];
                    unionP(0, p);
                }
            }
            if (ans > k) {
                System.out.println("Oh no");
            } else
            {
                System.out.println(ans);
            }
        }

        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            want = new int[n + 1];
            parent = new int[n + 1];
            st = new StringTokenizer(br.readLine(), " ");
            for (int i = 1; i <= n; i++) {
                want[i] = Integer.parseInt(st.nextToken());
                parent[i] = i;
            }
            for (int i = 1; i <= m; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                unionP(v, w);
            }
        }

        int findP(int a) {
            if (parent[a] != a) {
                parent[a] = findP(parent[a]);
            }
            return parent[a];
        }
        void unionP(int a, int b) {
            a = findP(a);
            b = findP(b);

            if (want[a] <= want[b]) {
                parent[b] = a;
            } else {
                parent[a] = b;
            }
        }
    }
}

