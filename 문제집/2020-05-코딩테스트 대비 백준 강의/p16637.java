import java.io.*;
import java.util.*;

public class p16637 {
    static int n;
    static int[] nums;
    static char[] ops;
    static long ans = Long.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        input();
        sol(nums, ops, 0);
        System.out.println(ans);
    }
    static void sol(int[] nums, char[] ops, int now) {
//        for (int num : nums) {
//            System.out.print(num + " ");
//        }
//        System.out.println();
//        for (char op : ops) {
//            System.out.print(op + " ");
//        }
//        System.out.println();
        ans = Math.max(ans, calc(nums, ops));
//        System.out.println(ans);
        for (; now < ops.length; now++) {
            for (int i = now; i < ops.length; i += 2) {
                long now_new_num = calc(nums[i], nums[i + 1], ops[i]);
                int[] new_nums = new int[nums.length - 1];
                char[] new_ops = new char[ops.length - 1];
                for (int j = 0; j < nums.length - 1; j++) {
                    if (j < i) new_nums[j] = nums[j];
                    else if (j == i) new_nums[j] = (int)now_new_num;
                    else new_nums[j] = nums[j + 1];
                }
                for (int j = 0; j < ops.length - 1; j++) {
                    if (j < i) new_ops[j] = ops[j];
                    else new_ops[j] = ops[j + 1];
                }
                sol(new_nums, new_ops, i + 1);
            }
        }
    }
    static long calc(int a, int b, int op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            default:
                return 0;
        }
    }
    static long calc(int[] nums, char[] ops) {
        long res = nums[0];
        for (int i = 0; i < ops.length; i++) {
            switch (ops[i]) {
                case '+':
                    res += nums[i + 1];
                    break;
                case '-':
                    res -= nums[i + 1];
                    break;
                case '*':
                    res *= nums[i + 1];
                    break;
            }
        }
        return res;
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        line = br.readLine();
        nums = new int[n / 2 + 1];
        ops = new char[n / 2];
        int ni = 0, oi = 0;
        for (int i = 0; i < n; i++) {
            if (line.charAt(i) == '+' || line.charAt(i) == '-' || line.charAt(i) == '*') {
                ops[oi++] = line.charAt(i);
            } else {
                nums[ni++] = (int) line.charAt(i) - (int) '0';
            }
        }
    }
}
