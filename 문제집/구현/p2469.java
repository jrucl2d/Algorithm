import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p2469 {
    static int k, n, stop;
    static char[] want;
    static String[] ops;
    static char[] s;

    public static void main(String[] args) throws IOException {
        input();
        for (int i = n - 1; i > stop; i--) {
            sol(want, ops[i]);
        }
        get_ans();
    }

    static void get_ans() {
        StringBuilder sb = new StringBuilder();
        boolean nope = false;
        for (int i = 0; i < k - 1; i++) {
            if (s[i] == want[i]) {
                sb.append("*");
            } else if (s[i] == want[i + 1] && want[i] == s[i + 1]) {
                sb.append("-");
                swap(want, i, i + 1);
            } else {
                for (int j = 0; j < k - 1; j++) {
                    System.out.print("x");
                }
                nope = true;
                break;
            }
        }
        if (!nope) {
            System.out.println(sb);
        }
    }

    static void sol(char[] s, String op) {
        for (int i = 0; i < k - 1; i++) {
            if (op.charAt(i) == '-') {
                swap(s, i, i + 1);
                i += 1;
            }
        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        k = Integer.valueOf(br.readLine());
        s = new char[k];
        for (int i = 0; i < k; i++) {
            s[i] = (char) ((int) 'A' + i);
        }
        n = Integer.valueOf(br.readLine());
        String want_tmp = br.readLine();
        want = new char[k];
        for (int i = 0; i < k; i++) {
            want[i] = want_tmp.charAt(i);
        }
        ops = new String[n];
        boolean doit = true;
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            ops[i] = line;
            if (line.charAt(0) == '?') {
                doit = false;
                stop = i;
            }
            if (doit) {
                sol(s, line);
            }
        }
    }

    static void swap(char[] arr, int a, int b) {
        char tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
}