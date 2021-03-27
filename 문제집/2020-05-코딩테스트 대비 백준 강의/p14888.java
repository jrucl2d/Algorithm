import java.io.*;
import java.util.*;

public class p14888 {
    static int n;
    static int[] arr;
    static int[] ops; // +, -, *, /
    static long the_max = Long.MIN_VALUE;
    static long the_min = Long.MAX_VALUE;
    static int[] visiting;

    public static void main(String[] args) throws IOException {
        input();
        sol(0);
        System.out.println(the_max);
        System.out.println(the_min);
    }
    static void sol(int cnt) {
        if (ops[0] == 0 && ops[1] == 0 && ops[2] == 0 && ops[3] == 0) {
            int now = arr[0];
            for (int i = 0; i < n - 1; i++) {
                switch (visiting[i]) {
                    case 0:
                        now += arr[i + 1];
                        break;
                    case 1:
                        now -= arr[i + 1];
                        break;
                    case 2:
                        now *= arr[i + 1];
                        break;
                    case 3:
                        now /= arr[i + 1];
                        break;
                }
            }
            the_max = Math.max(the_max, now);
            the_min = Math.min(the_min, now);
        }
        for (int i = 0; i < 4; i++) {
            if (ops[i] > 0) {
                visiting[cnt] = i;
                ops[i] -= 1;
                sol(cnt + 1);
                ops[i] += 1;
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        arr = new int[n];
        visiting = new int[n - 1];
        line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        ops = new int[4];
        for (int i = 0; i < 4; i++) {
            ops[i] = Integer.valueOf(st.nextToken());
        }
    }
}
