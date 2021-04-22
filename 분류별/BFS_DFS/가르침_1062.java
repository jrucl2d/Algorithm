import java.io.*;
import java.util.*;

public class Main {
    static int n, k, ans = 0;
    static int[] arr;
    static int visited;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken()) - 5;
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            String tmp = br.readLine();
            for (int j = 0; j < tmp.length(); j++) {
                arr[i] = arr[i] | (1 << tmp.charAt(j) - 'a');
            }
        }
        if (k < 0) {
            System.out.println(0);
            return;
        }
        visited = visited | 1;
        visited = visited | (1 << ('c' - 'a'));
        visited = visited | (1 << ('i' - 'a'));
        visited = visited | (1 << ('n' - 'a'));
        visited = visited | (1 << ('t' - 'a'));

        dfs(0, 0);
        System.out.println(ans);
    }

    static void dfs(int index, int start) {
        if (index == k) {
            int inner_count = 0;
            for (int now : arr) {
                if ((now & visited) == now) {
                    inner_count += 1;
                }
            }
            ans = Math.max(ans, inner_count);
            return;
        }
        for (int i = start; i < 26; i++) {
            if ((visited & (1 << i)) == (1 << i))
                continue;
            visited += (1 << i);
            dfs(index + 1, i + 1);
            visited -= (1 << i);
        }
    }
}