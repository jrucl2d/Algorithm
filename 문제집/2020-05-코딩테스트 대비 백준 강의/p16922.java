import java.io.*;
import java.util.*;

public class p16922 {
    static int n;
    static int[] nums = {1, 5, 10, 50};
    static int[] visited;
    static boolean[] made;
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        input();
        sol(0, 0);
        print();
    }
    static void print() {
        System.out.println(ans);
    }
    static void sol(int cnt, int st) {
        if (cnt == n) {
            int inner_ans = 0;
            for (int num : visited) {
                inner_ans += num;
            }
            if (!made[inner_ans]) {
                ans += 1;
                made[inner_ans] = true;
            }
            return;
        }
        for (int i = st; i < 4; i++) {
            visited[cnt] = nums[i];
            sol(cnt + 1, i);
        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        visited = new int[n];
        made = new boolean[1010];
    }
}
