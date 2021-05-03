import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int r = Integer.valueOf(st.nextToken());
        int c = Integer.valueOf(st.nextToken());
        int[][] arr = new int[r][c];
        for (int i = 0; i < r; i++) {
            String line = br.readLine();
            for (int j = 0; j < c; j++) {
                arr[i][j] = line.charAt(j) - 'A';
            }
        }
        Solution solution = new Solution();
        System.out.println(solution.solution(arr));
    }
    static class Solution {
        int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
        int ans = -1;
        public int solution(int[][] arr) {
            go(0, 0, 1, 1 << arr[0][0], arr);
            return ans;
        }
        void go(int x, int y, int cnt, int visited, int[][] arr) {
            boolean can_go = false;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= arr.length || ny >= arr[0].length) continue;
                if ((visited & (1 << arr[nx][ny])) == (1 << arr[nx][ny])) continue;
                visited += (1 << arr[nx][ny]);
                can_go = true;
                go(nx, ny, cnt + 1, visited, arr);
                visited -= (1 << arr[nx][ny]);
            }
            if (!can_go) {
                ans = Math.max(ans, cnt);
                return;
            }
        }
    }
}
