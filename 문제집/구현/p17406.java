import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class p17406 {
    static int n, m, k, ans = Integer.MAX_VALUE;
    static int[][] arr;
    static int[][] ops;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        input();
        for (int i = 0; i < k; i++) {
            Stack<Integer> visiting = new Stack<>();
            visited = new boolean[k];
            dfs(i, visiting);
        }
        System.out.println(ans);
    }
    static void dfs(int index, Stack<Integer> visiting) {
        // 체크인
        visited[index] = true;
        visiting.add(index);
        // 종료 조건
        if (visiting.size() == k) {
            sol(visiting);
        }
        // 갈 수 있으면 간다
        for (int i = 0; i < k; i++) {
            if (visited[i] == false) {
                dfs(i, visiting);
            }
        }
        // 체크 아웃
        visited[index] = false;
        visiting.pop();
    }
    static void sol(Stack<Integer> visiting) {
        int[][] tmp_arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp_arr[i][j] = arr[i][j];
            }
        }
        for (int ind = 0; ind < k; ind++) {
            int i = visiting.indexOf(ind);
            int s1 = ops[i][0] - ops[i][2];
            int e1 = ops[i][0] + ops[i][2];
            int s2 = ops[i][1] - ops[i][2];
            int e2 = ops[i][1] + ops[i][2];
            while(true) {
                rotate(tmp_arr, s1 - 1, e1 - 1, s2 - 1, e2 - 1);
                s1++; e1--; s2++; e2--;
                if (s1 >= e1) break;
            }
        }
        for (int i = 0; i < n; i++) {
            int inner_sum = 0;
            for (int j = 0; j < m; j++) {
                inner_sum += tmp_arr[i][j];
            }
            ans = Math.min(ans, inner_sum);
        }
    }

    static void rotate(int[][] arr, int rs, int re, int cs, int ce) {
        int first = arr[rs][cs];
        for (int i = rs; i < re; i++) {
            arr[i][cs] = arr[i + 1][cs];
        }
        for (int j = cs; j < ce; j++) {
            arr[re][j] = arr[re][j + 1];
        }
        for (int i = re; i > rs; i--) {
            arr[i][ce] = arr[i - 1][ce];
        }
        for (int j = ce; j > cs; j--) {
            arr[rs][j] = arr[rs][j - 1];
        }
        arr[rs][cs + 1] = first;
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken());
        arr = new int[n][m];
        ops = new int[k][3];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
        for(int i = 0; i < k; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            ops[i][0] = Integer.valueOf(st.nextToken());
            ops[i][1] = Integer.valueOf(st.nextToken());
            ops[i][2] = Integer.valueOf(st.nextToken());
        }
    }
}
