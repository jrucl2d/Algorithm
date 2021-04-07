import java.util.*;
class Solution {
    int[][] arr;
    public int solution(int m, int n, String[] board) {
        int answer = 0;
        arr = toInteger(m, n, board);
        List<Point> list;
        
        while (true) {
            list = new ArrayList<>();
            boolean is_changed = false;
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (isSquare(i, j)) {
                        list.add(new Point(i, j));
                        is_changed = true;
                    }
                }
            }
            if (!is_changed) break;
            for (Point p : list) {
                if (arr[p.x][p.y] != 0) { answer += 1; arr[p.x][p.y] = 0; }
                if (arr[p.x + 1][p.y] != 0) { answer += 1; arr[p.x + 1][p.y] = 0; }
                if (arr[p.x][p.y + 1] != 0) { answer += 1; arr[p.x][p.y + 1] = 0; }
                if (arr[p.x + 1][p.y + 1] != 0) { answer += 1; arr[p.x + 1][p.y + 1] = 0; }
            }
            for (int j = 0; j < n; j++) {
                int[] line = new int[m];
                int index = 0;
                for (int i = m - 1; i >= 0; i--) {
                    if (arr[i][j] != 0) line[index++] = arr[i][j];
                }
                for (int i = m - 1; i >= 0; i--) {
                    arr[i][j] = line[m - i - 1];
                }
            }
        }
        return answer;
    }
    boolean isSquare(int i, int j) {
        if (arr[i][j] == arr[i][j + 1] && arr[i][j] == arr[i + 1][j] 
            && arr[i][j] == arr[i + 1][j + 1] && arr[i][j] != 0) {
            return true;
        }
        return false;
    }
    int[][] toInteger(int m, int n, String[] board) {
        int[][] arr = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = (int)board[i].charAt(j) - (int)'A' + 1;
            }
        }
        return arr;
    }
    class Point {
        int x, y;
        Point(int a, int b) {x=a;y=b;}
    }
}