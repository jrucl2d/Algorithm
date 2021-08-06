import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main
{
    static int n;
    static int[] arr;
    static int[] ans;
    static int[] visiting;
    static boolean[] visited;
    static boolean end = false;
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        visited = new boolean[n];
        visiting = new int[n];
        ans = new int[n * 2];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < 2 * n; i++) ans[i] = -1;
        Arrays.sort(arr);
        dfs(0);
        if (!end) System.out.println(-1);
    }
    static void dfs(int index) {
        if (end) return;
        if (index == 2 * n) {
            for (int a : ans) {
                System.out.print(a + " ");
            }
            end = true;
            return;
        }
        if (ans[index] != -1) {
            dfs(index + 1);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            int nextIndex = index + arr[i] + 1;
            if (nextIndex < n * 2 && ans[nextIndex] == -1) {
                visited[i] = true;
                ans[index] = ans[nextIndex] = arr[i];
                dfs(index + 1);
                ans[index] = ans[nextIndex] = -1;
                visited[i] = false;
            }
        }
    }
}

