import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Solution solution = new Solution();
        solution.solution();
    }
    static class Solution {
        int n, sum = 0, twoCnt = 0;
        int[] arr;
        public void solution() throws IOException {
            input();
            System.out.println(logic() ? "YES" : "NO");
        }
        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            n = Integer.parseInt(br.readLine());
            arr = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int i = 0; i < n; i++) {
                int now = Integer.parseInt(st.nextToken());
                sum += now;
                arr[i] = now;
                twoCnt += (now / 2);
            }
        }
        boolean logic() {
            if (sum % 3 != 0) return false;
            if (sum / 3 > twoCnt) return false;
            return true;
        }
    }
}

