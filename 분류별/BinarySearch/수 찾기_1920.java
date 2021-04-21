import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] arr;
    static long ans;

    public static void main(String[] args) throws IOException {
        input();

    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        arr = new int[n];
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
        Arrays.sort(arr);
        m = Integer.valueOf(br.readLine());
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        int now;
        for (int i = 0; i < m; i++) {
            now = Integer.valueOf(st.nextToken());
            if (find(now, 0, n - 1))
                System.out.println(1);
            else
                System.out.println(0);
        }
    }

    static boolean find(int num, int l, int r) {
        if (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] > num) {
                return find(num, l, mid - 1);
            }
            if (arr[mid] < num) {
                return find(num, mid + 1, r);
            }
            return true;
        }
        return false;
    }

}