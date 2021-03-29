import java.io.*;
import java.util.*;

public class p16946 {
    static int n, m;
    static int[][] arr;
    static int[][] visited;
    static int[][] group;
    static int group_index = 1;
    static int count = 0;
    static int index = 0;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        input();
        sol();
        print();
    }
    static void print() {
        boolean[] group_visited = new boolean[group_index + 2];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == -1) {
                    for (int d = 0; d < group_index + 2; d++) group_visited[d] = false;
                    int inner_sum = 0;
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == -1) continue;
                        if (group_visited[group[nx][ny]]) continue;
                        group_visited[group[nx][ny]] = true;
                        inner_sum += arr[nx][ny];
                    }
                    sb.append((inner_sum + 1) % 10);
                }
                else sb.append(0);
            }
            sb.append("\n");
        }
        System.out.println(sb);
    }
    static void sol() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    count = 0;
                    index = 0;
                    dfs(i, j);
                    for (int a = 0; a < index; a++) {
                        arr[visited[a][0]][visited[a][1]] = count;
                        group[visited[a][0]][visited[a][1]] = group_index;
                    }
                    group_index += 1;
                }
            }
        }
    }
    static void dfs(int x, int y) {
        // 체크인
        arr[x][y] = 1;
        count += 1;
        visited[index][0] = x; visited[index][1] = y;
        index += 1;
        // 갈 수 있으면 간다.
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (arr[nx][ny] == 0) dfs(nx, ny);
        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        arr = new int[n][m];
        group = new int[n][m];
        visited = new int[1000010][2];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = line.charAt(j) - (int)'0';
                arr[i][j] = arr[i][j] == 1 ? -1 : 0;
            }
        }
    }
}
