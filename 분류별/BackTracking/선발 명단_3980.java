import java.io.*;
import java.util.*;

public class Main {
    static int c, ans = 0;
    static int[][] arr;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        c = Integer.valueOf(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (c-- > 0) {
            visited = new boolean[11];
            arr = new int[11][11];
            ans = 0;
            for (int i = 0; i < 11; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < 11; j++) {
                    arr[i][j] = Integer.valueOf(st.nextToken());
                }
            }
            dfs(0, 0);
            sb.append(ans + "\n");
        }
        System.out.println(sb);
    }

    static void dfs(int index, int sum) {
        if (index == 11) {
            ans = Math.max(ans, sum);
            return;
        }
        for (int i = 0; i < 11; i++) {
            if (arr[i][index] == 0)
                continue;
            if (visited[i])
                continue;
            visited[i] = true;
            dfs(index + 1, sum + arr[i][index]);
            visited[i] = false;
        }
    }
}