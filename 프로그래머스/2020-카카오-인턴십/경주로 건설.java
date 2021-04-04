class Solution {
    final int STRAIGHT = 100;
    final int CORNER = 500;
    int[][][] visited;
    int[][] board;
    int n;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    public int solution(int[][] boards) {
        board = boards;
        n = board.length;
        visited = new int[n][n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) visited[i][j][0] = visited[i][j][1] = Integer.MAX_VALUE;
        }
        visited[0][0][0] = 0;
        visited[0][0][1] = 0;
        dfs(0, 0, true);
        dfs(0, 0, false);
        return Math.min(visited[n - 1][n - 1][0], visited[n - 1][n - 1][1]);
    }
    void dfs(int x, int y, boolean is_vertical) {
        if (x == n - 1 && y == n - 1) {
            return;
        }
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 1) continue;
            int next_val = 0;
            if (d < 2) {
                if (is_vertical) {
                    next_val = visited[x][y][1] + STRAIGHT;
                    if (next_val > visited[nx][ny][1]) continue;
                    visited[nx][ny][1] = next_val;
                    dfs(nx, ny, true);
                    continue;
                }
                next_val = visited[x][y][0] + STRAIGHT + CORNER;
                if (next_val > visited[nx][ny][1]) continue;
                visited[nx][ny][1] = next_val;
                dfs(nx, ny, true);
                continue;
            }
            if (is_vertical) {
                next_val = visited[x][y][1] + STRAIGHT + CORNER;
                if (next_val > visited[nx][ny][0]) continue;
                visited[nx][ny][0] = next_val;
                dfs(nx, ny, false);
                continue;
            }
            next_val = visited[x][y][0] + STRAIGHT;
            if (next_val > visited[nx][ny][0]) continue;
            visited[nx][ny][0] = next_val;
            dfs(nx, ny, false);
            continue;
        }
    }
}