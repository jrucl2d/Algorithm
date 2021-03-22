import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class p9934 {
    static int n;
    static int nn;
    static int[] arr;
    static int[] ans;
    static int now;

    public static void main(String[] args) throws IOException {
        input();
        now = 1;
        for (int i = 0; i < nn; i++) {
            sol(i);
        }
        print();
    }

    static void sol(int index) {
        int left_child = now * 2;
        if (left_child <= nn) {
            if (ans[left_child] == 0) {
                now = left_child;
                sol(index);
            } else if (ans[now] == 0) {
                ans[now] = arr[index];
            } else if (ans[left_child + 1] == 0) {
                now = left_child + 1;
                sol(index);
            } else {
                now /= 2;
                sol(index);
            }
        } else if (ans[now] == 0) {
            ans[now] = arr[index];
        } else {
            now /= 2;
            sol(index);
        }
    }

    static void input() throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(bf.readLine());
        nn = 0;
        for (int i = 0; i < n; i++) {
            nn += (int) Math.pow(2, i);
        }
        arr = new int[nn];
        ans = new int[nn + 1];
        String line = bf.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        int i = 0;
        while (st.hasMoreTokens()) {
            arr[i] = Integer.valueOf(st.nextToken());
            i += 1;
        }
    }

    static void print() {
        int jump_index = 1;
        for (int i = 1; i <= nn; i++) {
            if ((int) Math.pow(2, jump_index) == i) {
                System.out.println();
                jump_index += 1;
            }
            System.out.print(ans[i] + " ");
        }
    }
}
