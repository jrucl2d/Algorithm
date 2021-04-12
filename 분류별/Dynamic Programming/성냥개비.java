import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static long[] min_arr = new long[101];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        beforeTask();
        int num;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            num = Integer.valueOf(br.readLine());
            String the_max = getMax(num);
            long the_min = min_arr[num];
            sb.append(the_min).append(" ").append(the_max).append("\n");
        }
        System.out.println(sb);
    }

    static void beforeTask() {
        Arrays.fill(min_arr, Long.MAX_VALUE);
        min_arr[2] = 1; min_arr[3] = 7; min_arr[4] = 4; min_arr[5] = 2;
        min_arr[6] = 6; min_arr[7] = 8; min_arr[8] = 10;
        int[] plus = {1, 7, 4, 2, 0, 8};
        for (int now = 9; now < 101; now++) {
            for (int j = 2; j < 8; j++) {
                String next = "" + min_arr[now - j] + plus[j - 2];
                min_arr[now] = Math.min(min_arr[now], Long.valueOf(next));
            }
        }
    }

    static String getMax(int num) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < num / 2; i++)  {
            sb.append(1);
        }
        if (num % 2 != 0) sb.setCharAt(0, '7');
        return sb.toString();
    }
}
