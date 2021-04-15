import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static long[] arr = new long[100];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr[1] = 1;
        arr[2] = 1;
        arr[3] = 2;
        for (int i = 4; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        System.out.println(arr[n]);
    }
}
