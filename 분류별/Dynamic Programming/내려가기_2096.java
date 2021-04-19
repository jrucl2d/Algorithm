import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] arr, min, max;

    public static void main(String[] args) throws IOException {
        input();

    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr = new int[3];
        min = new int[3];
        max = new int[3];
        String line;
        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < 3; j++) {
                arr[j] = Integer.valueOf(st.nextToken());
            }
            if (i == 0) {
                min[0] = max[0] = arr[0];
                min[1] = max[1] = arr[1];
                min[2] = max[2] = arr[2];
                continue;
            }
            int nmin0 = Math.min(min[0] + arr[0], min[1] + arr[0]);
            int nmin1 = Math.min(Math.min(min[0] + arr[1], min[1] + arr[1]), min[2] + arr[1]);
            int nmin2 = Math.min(min[1] + arr[2], min[2] + arr[2]);
            min[0] = nmin0;
            min[1] = nmin1;
            min[2] = nmin2;
            int nmax0 = Math.max(max[0] + arr[0], max[1] + arr[0]);
            int nmax1 = Math.max(Math.max(max[0] + arr[1], max[1] + arr[1]), max[2] + arr[1]);
            int nmax2 = Math.max(max[1] + arr[2], max[2] + arr[2]);
            max[0] = nmax0;
            max[1] = nmax1;
            max[2] = nmax2;
        }
        System.out
                .println(Math.max(Math.max(max[0], max[1]), max[2]) + " " + Math.min(Math.min(min[0], min[1]), min[2]));
    }
}