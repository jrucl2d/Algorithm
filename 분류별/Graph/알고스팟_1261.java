import java.io.*;
import java.util.*;

public class Main {
	final static int INF = 987654321;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int m = Integer.valueOf(st.nextToken());
		int n = Integer.valueOf(st.nextToken());
		int[][] arr = new int[n][m];
		int[][] distance = new int[n][m];
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			for (int j = 0; j < m; j++) {
				distance[i][j] = INF;
				arr[i][j] = line.charAt(j) - '0';
			}
		}
		distance[0][0] = 0;
		PriorityQueue<Info> q = new PriorityQueue<>((aa, bb) -> aa.cost - bb.cost);
		q.add(new Info(0, 0, 0));
		int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
		while (!q.isEmpty()) {
			Info now = q.remove();
			if (now.x == n - 1 && now.y == m - 1) break;
			if (distance[now.x][now.y] < now.cost) continue;
			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i], ny = now.y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				int plus = 0;
				if (arr[nx][ny] == 1) plus += 1;
				if (distance[nx][ny] > distance[now.x][now.y] + plus) {
					distance[nx][ny] = distance[now.x][now.y] + plus;
					q.add(new Info(nx, ny, distance[nx][ny]));
				}
			}
		}
		System.out.println(distance[n - 1][m - 1]);
	}
	static class Info {
		int x, y, cost;
		Info (int x, int y, int cost) {this.x=x; this.y=y; this.cost=cost;}
	}
}
