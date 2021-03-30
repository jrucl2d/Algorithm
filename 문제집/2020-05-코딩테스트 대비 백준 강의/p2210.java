import java.io.*;
import java.util.*;

public class p2210 {
    static int[][] arr;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
    static Set<String> set = new HashSet<>();
    static int ans = 0;
    public static void main(String[] args) throws IOException {
        input();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                sol(i, j);
            }
        }
        System.out.println(ans);
    }
    static void sol(int x, int y) {
        Stack<Info> stack = new Stack<>();
        stack.add(new Info(x, y, String.valueOf(arr[x][y])));
        while (!stack.isEmpty()) {
            Info now = stack.pop();
            if (now.s.length() == 6) {
                int before = set.size();
                set.add(now.s);
                if (before != set.size()) {
                    ans += 1;
                }
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
                stack.add(new Info(nx, ny, now.s + arr[nx][ny]));
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringTokenizer st;
        arr = new int[5][5];
        for (int i = 0; i < 5; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < 5; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
    }
    static class Info {
        int x, y;
        String s;
        Info(int x, int y, String s) {this.x = x; this.y = y; this.s = s;}
    }
}
