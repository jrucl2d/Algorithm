import java.io.*;
import java.util.StringTokenizer;

public class p15652 {
    static int n, m;
    static int[] arr;
    static BufferedWriter br;
    public static void main(String[] args) throws IOException {
        br = new BufferedWriter(new OutputStreamWriter(System.out));
        input();
        for (int i = 1; i <= n; i++) {
            sol(i, 1);
        }
        br.flush();
    }
    static void sol(int now, int index) throws IOException {
        // 체크 인
        arr[index] = now;
        // 종료 조건
        if (index == m) {
            for (int i = 1; i <= m; i++) {
                br.write(arr[i] + " ");
            }
            br.newLine();
            index -= 1;
            return;
        }

        // 갈 수 있으면 간다.
        for (int i = now; i <= n; i++) {
            sol(i, index + 1);
        }
        index -= 1;
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        arr = new int[m + 1];
    }
}
