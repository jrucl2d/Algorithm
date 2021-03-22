import java.util.Scanner;

public class p2877 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sol(n);
    }
    static void sol(int n) {
        int the_sum = 0;
        int the_len = 0;
        while(true) {
            the_len += 1;
            int now_calc = (int)Math.pow(2, the_len);
            if (the_sum + now_calc < n) {
                the_sum += now_calc;
            } else {
                break;
            }
        }
        StringBuilder sb = new StringBuilder();
        int now = n - the_sum, len = (int)Math.pow(2, the_len);
        for(int i = 0; i < the_len; i++) {
            if (len / 2 >= now) {
                sb.append('4');
                len /= 2;
            } else {
                sb.append('7');
                now -= (len / 2);
                len /= 2;
            }
        }
        System.out.println(sb);
    }
}
