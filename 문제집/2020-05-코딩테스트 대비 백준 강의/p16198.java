import java.io.*;
import java.util.*;

public class p16198 {
    static int fn;
    static int[] arr;
    static long ans = Long.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        input();
        sol(arr, 0);
        System.out.println(ans);
    }
    static void sol(int[] now, int cnt) {
        int n = now.length;
        if (n == 2) {
            ans = Math.max(ans, cnt);
            return;
        }
        for (int pick = 1; pick < n - 1; pick++) {
            int[] newNow = getNew(now, pick);
            sol(newNow, cnt + now[pick - 1] * now[pick + 1]);
        }
    }
    static int[] getNew(int[] now, int pick) {
        int n = now.length;
        int[] newNow = new int[n - 1];
        for (int i = 0; i < n; i++) {
            if (i == pick) continue;
            if (i < pick) newNow[i] = now[i];
            else newNow[i - 1] = now[i];
        }
        return newNow;
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        fn = Integer.valueOf(line);
        arr = new int[fn];
        line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        for (int i = 0; i < fn; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
    }
}
