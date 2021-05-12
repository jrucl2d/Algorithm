import java.io.*;
import java.util.*;

public class Main {
	static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
	static Point[] swans = new Point[2];
	static int n, m;
	static char[][] arr;
	static boolean[][] visited;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.valueOf(st.nextToken());
		m = Integer.valueOf(st.nextToken());
		arr = new char[n][m];
		visited = new boolean[n][m];
		Queue<Point> waterQ = new LinkedList<>();
		swans[0] = new Point(-1, -1);
		swans[1] = new Point(-1, -1);
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < m; j++) {
				arr[i][j] = line.charAt(j);
				if (arr[i][j] != 'X') waterQ.add(new Point(i, j));
				if (arr[i][j] == 'L') {
					if (swans[0].x == -1) {
						swans[0] = new Point(i, j);
						continue;
					}
					swans[1] = new Point(i, j);
				}
			}
		}
		Queue<Point> swanQ = new LinkedList<>();
		swanQ.add(swans[0]);
		visited[swans[0].x][swans[0].y] = true;
		int ans = 0;
		while (true) {
			Queue<Point> swanNextQ = new LinkedList<>();
			while(!swanQ.isEmpty()) {
				Point now = swanQ.remove();
				for (int d = 0; d < 4; d++) {
					int nx = now.x + dx[d], ny = now.y + dy[d];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (nx == swans[1].x && ny == swans[1].y) {
						System.out.println(ans);
						return;
					}
					if (arr[nx][ny] == '.' && !visited[nx][ny]) {
						swanQ.add(new Point(nx, ny));
						visited[nx][ny] = true;
					}
					if (arr[nx][ny] == 'X' && !visited[nx][ny]) {
						swanNextQ.add(new Point(nx, ny));
						visited[nx][ny] = true;
					}
				}
			}
			swanQ = swanNextQ;
			// 얼음을 녹인다.
			int waterSize = waterQ.size();
			for (int i = 0; i < waterSize; i++) {
				Point now = waterQ.remove();
				for (int d = 0; d < 4; d++) {
					int nx = now.x + dx[d], ny = now.y + dy[d];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					if (arr[nx][ny] == 'X') {
						waterQ.add(new Point(nx, ny));
						arr[nx][ny] = '.';
					}
				}
			}
			ans += 1;
		}
	}

	static class Point {
		int x, y;
		Point(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
}
