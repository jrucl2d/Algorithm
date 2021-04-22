import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static String[] arr;

    public static void main(String[] args) throws IOException {
        input();

    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        arr = new String[n];
        Info[] table = new Info[26];
        for (int i = 0; i < 26; i++) {
            table[i] = new Info((char) (i + (int) 'A'), 0);
        }
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            arr[i] = line;
            int the_sum = 1;
            for (int j = line.length() - 1; j >= 0; j--) {
                int table_index = line.charAt(j) - 'A';
                table[table_index].num += the_sum;
                the_sum *= 10;
            }
        }
        Arrays.sort(table, (a, b) -> b.num - a.num);

        Map<Character, Integer> map = new HashMap<>();
        int val = 9;
        for (int i = 0; i < 26; i++) {
            if (table[i].num == 0)
                break;
            map.put(table[i].c, val--);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += getNum(arr[i], map);
        }
        System.out.println(ans);
    }

    static int getNum(String a, Map<Character, Integer> map) {
        int ret = 0;
        for (int i = 0; i < a.length(); i++) {
            ret *= 10;
            ret += map.get(a.charAt(i));
        }
        return ret;
    }

    static class Info {
        char c;
        int num;

        Info(char c, int num) {
            this.c = c;
            this.num = num;
        }
    }
}