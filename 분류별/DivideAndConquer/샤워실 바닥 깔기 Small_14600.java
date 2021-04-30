import java.io.*;
import java.util.*;

public class Main {
    static int k, x, y, n;
    static int[][] arr;
    static int[][][] tiles = { { { 1, 1 }, { 0, 1 } }, { { 1, 1 }, { 1, 0 } }, { { 0, 1 }, { 1, 1 } },
            { { 1, 0 }, { 1, 1 } } };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Integer.valueOf(br.readLine());
        n = (int) Math.pow(2, k);
        arr = new int[n][n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        x = Integer.valueOf(st.nextToken());
        y = Integer.valueOf(st.nextToken());
        arr[n - y][x - 1] = -1;
        dfs(arr, 1);
        System.out.println(-1);
    }

    static void dfs(int[][] arr, int num) {
        if (isDone(arr)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(arr[i][j] + " ");
                }
                System.out.println();
            }
            System.exit(0);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                for (int k = 0; k < 4; k++) {
                    if (canTiling(arr, i, j, k, num)) {
                        dfs(arr, num + 1);
                        unTiling(arr, i, j, k, num);
                    }
                }
            }
        }
    }

    static boolean canTiling(int[][] arr, int x, int y, int tile_num, int num) {
        int[][] now_tile = tiles[tile_num];
        if ((arr[x][y] > 0 || arr[x][y] == -1) && now_tile[0][0] == 1)
            return false;
        if ((arr[x + 1][y] > 0 || arr[x + 1][y] == -1) && now_tile[1][0] == 1)
            return false;
        if ((arr[x][y + 1] > 0 || arr[x][y + 1] == -1) && now_tile[0][1] == 1)
            return false;
        if ((arr[x + 1][y + 1] > 0 || arr[x + 1][y + 1] == -1) && now_tile[1][1] == 1)
            return false;

        if (now_tile[0][0] == 1)
            arr[x][y] += num;
        if (now_tile[0][1] == 1)
            arr[x][y + 1] += num;
        if (now_tile[1][0] == 1)
            arr[x + 1][y] += num;
        if (now_tile[1][1] == 1)
            arr[x + 1][y + 1] += num;
        return true;
    }

    static void unTiling(int[][] arr, int x, int y, int tile_num, int num) {
        int[][] now_tile = tiles[tile_num];
        if (now_tile[0][0] == 1)
            arr[x][y] -= num;
        if (now_tile[0][1] == 1)
            arr[x][y + 1] -= num;
        if (now_tile[1][0] == 1)
            arr[x + 1][y] -= num;
        if (now_tile[1][1] == 1)
            arr[x + 1][y + 1] -= num;
    }

    static boolean isDone(int[][] arr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
}