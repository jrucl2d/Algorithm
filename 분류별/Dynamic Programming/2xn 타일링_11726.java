import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 10007;
    static int n;
    static int[] arr = new int[1010];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr[1] = 1;
        arr[2] = 2;
        for (int i = 3; i <= n; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
        }
        System.out.println(arr[n] % MOD);
    }
}
