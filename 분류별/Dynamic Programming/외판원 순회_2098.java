import java.io.*;
import java.util.*;

public class Main {
    static final int INF = 987654321;
    static int n, end;
    static int[][] arr;
    static int[][] dp; // 현재 i 번째 노드 방문중이고, j의 방문 기록을 가졌을 경

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(sol(0, 0));
    }

    static int sol(int visited, int now) {
        // 체크인
        visited = visited | (1 << now);
        // 종료 조건 -> 0에서 출발했으므로 0으로 간다.
        if (visited == end) {
            if (arr[now][0] == 0)
                return INF; // 최대 길이를 리턴해서 최소값에서 제외되도록
            return arr[now][0];
        }
        // 갈 수 있으면 간다
        if (dp[now][visited] != 0)
            return dp[now][visited];
        dp[now][visited] = INF;
        for (int i = 0; i < n; i++) {
            if ((visited & (1 << i)) != 0)
                continue;
            if (arr[now][i] == 0)
                continue;
            dp[now][visited] = Math.min(dp[now][visited], arr[now][i] + sol(visited, i));
        }
        return dp[now][visited];
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr = new int[n][n];
        end = (1 << n) - 1;
        dp = new int[n][end + 1];
        String line;
        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
    }
}