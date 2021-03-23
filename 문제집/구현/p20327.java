import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p20327 {
    static int n, r, nn;
    static int[][] arr;
    static int[][] ops;
    public static void main(String[] args) throws IOException {
        input();
        sol();
        print();
    }
    static void sol() {
        for(int op = 0 ; op < r; op++) {
            int k = ops[op][0], a = ops[op][1];
            if (a == 0 && k < 5) continue;
            if (k >= 5) {
                for (int aa = n; aa > a; aa--) {
                    int jump = (int) Math.pow(2, aa);
                    for (int i = 0; i < nn; i += jump) {
                        for(int j = 0; j < nn; j+= jump) {
                            doing(i, j, jump, k - 4);
                        }
                    }
                }
                continue;
            }
            for (int aa = a; aa > 0; aa--) {
                int jump = (int) Math.pow(2, aa);
                for (int i = 0; i < nn; i += jump) {
                    for(int j = 0; j < nn; j+= jump) {
                        doing(i, j, jump, k);
                    }
                }
            }
        }
    }
    static void doing(int x, int y, int size, int k) {
        switch (k) {
            case 1:
                for (int i = 0; i < size / 2; i++) {
                    for (int j = 0; j < size; j++) {
                        swap(arr, x + i, y + j, x + i + size / 2, y + j);
                    }
                }
                break;
            case 2:
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size / 2; j++) {
                        swap(arr, x + i, y + j, x + i, y + j + size / 2);
                    }
                }
                break;
            case 3:
                for (int i = 0; i < size; i++) {
                    for(int j = 0; j < size / 2; j++) {
                        swap(arr, x + i, y + j, x + i, y + j + size / 2);
                    }
                }
                for (int i = 0; i < size / 2; i++) {
                    for (int j = 0; j < size / 2; j++) {
                        swap(arr, x + i, y + j, x + i + size / 2, y + j + size / 2);
                    }
                }
                break;
            case 4:
                for (int i = 0; i < size; i++) {
                    for(int j = 0; j < size / 2; j++) {
                        swap(arr, x + i, y + j, x + i, y + j + size / 2);
                    }
                }
                for (int i = size / 2; i < size; i++) {
                    for (int j = 0; j < size / 2; j++) {
                        swap(arr, x + i, y + j, x + i - size / 2, y + j + size / 2);
                    }
                }
                break;
            default:
                return;
        }
    }
    static void swap(int[][] arr, int x, int y, int x2, int y2) {
        int tmp = arr[x][y];
        arr[x][y] = arr[x2][y2];
        arr[x2][y2] = tmp;
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        r = Integer.valueOf(st.nextToken());
        nn = (int) Math.pow(2, n);
        arr = new int[nn][nn];
        ops = new int[r][2];
        for (int i = 0; i < nn; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < nn;j ++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
        for (int i = 0; i < r; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            ops[i][0] = Integer.valueOf(st.nextToken());
            ops[i][1] = Integer.valueOf(st.nextToken());
        }
    }
    static void print() {
        for (int i = 0; i < nn; i++) {
            for(int j = 0; j < nn; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }
}
