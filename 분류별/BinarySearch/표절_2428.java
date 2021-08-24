import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Solution solution = new Solution();
        solution.solution();
    }
    static class Solution {
        int n;
        int[] arr;

        public void solution() throws IOException {
            input();
            func();
        }

        void func() {
            long ans = 0;
            Arrays.sort(arr);
            for (int i = 1; i < n; i++) {
                double limit = arr[i] * 0.9;
                int index = lowerBound(0, i - 1, limit);
                if (index < 0 || index >= n) continue;
                if (arr[index] >= limit) ans += (i - index);
                else ans += (i - index - 1);
            }
            System.out.println(ans);
        }

        int lowerBound(int l, int r, double v) {
            if (l < r) {
                int m = (l + r) / 2;
                if (arr[m] >= v) {
                    return lowerBound(l, m, v);
                } else {
                    return lowerBound(m + 1, r, v);
                }
            }
            return r;
        }

        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
            }
        }
    }
}

