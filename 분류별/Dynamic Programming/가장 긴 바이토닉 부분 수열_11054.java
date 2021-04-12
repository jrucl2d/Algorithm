import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] arr;
    static int[] asc;
    static int[] desc;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
        asc = new int[n];
        desc = new int[n];
        setAsc();
        setDesc();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(asc[i] + desc[i] - 1, ans);
        }
        System.out.println(ans);
    }

    static void setAsc() {
        for (int i = 0; i < n; i++) {
            asc[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] <= arr[j])
                    continue;
                asc[i] = Math.max(asc[i], asc[j] + 1);
            }
        }
    }

    static void setDesc() {
        for (int i = n - 1; i >= 0; i--) {
            desc[i] = 1;
            for (int j = n - 1; j > i; j--) {
                if (arr[i] <= arr[j])
                    continue;
                desc[i] = Math.max(desc[i], desc[j] + 1);
            }
        }
    }
}
