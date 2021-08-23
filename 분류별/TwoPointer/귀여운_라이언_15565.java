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
        int n, k, ans = Integer.MAX_VALUE;
        int[] arr;

        public void solution() throws IOException {
            input();
            func();
            System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
        }

        void func() {
            int start = 0;
            int end = 0;
            int get = arr[0] == 1 ? 1 : 0;
            while (end != n) {
                if (get >= k) {
                    ans = Math.min(end - start + 1, ans);
                    if (end + 1 < n && arr[end + 1] == 1) {
                        get += 1;
                        end += 1;
                    }
                    if (arr[start] == 1) get -= 1;
                    start += 1;
                }
                else {
                    if (end + 1 < n && arr[end + 1] == 1) get += 1;
                    end += 1;
                }
            }
        }

        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());
            arr = new int[n];
            st = new StringTokenizer(br.readLine(), " ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
        }
    }
}

