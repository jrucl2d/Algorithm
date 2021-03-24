import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class p15650 {
    static int n, m;
    static boolean visited[];
    public static void main(String[] args) throws IOException {
        input();
        Stack<Integer> stack = new Stack<>();
        for (int i = 1; i <= n; i++) {
            sol(i, stack);
        }
    }
    static void sol(int now, Stack<Integer> stack) {
        // 체크 인
        visited[now] = true;
        stack.add(now);
        // 종료 조건
        boolean can_print = true;
        if (stack.size() == m) {
            for (int i = 0; i < m - 1; i++) {
                if (stack.get(i) > stack.get(i + 1)) {
                    can_print = false;
                    break;
                }
            }
            if (can_print == true) {
                for (int i = 0; i < m; i++) {
                    System.out.print(stack.get(i) + " ");
                }
                System.out.println();
            }
        }

        // 갈 수 있으면 간다.
        for (int i = 1; i <= n; i++) {
            if (visited[i] == false) {
                sol(i, stack);
            }
        }

        // 체크 아웃
        visited[now] = false;
        stack.pop();
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        visited = new boolean[n + 1];
    }
}
