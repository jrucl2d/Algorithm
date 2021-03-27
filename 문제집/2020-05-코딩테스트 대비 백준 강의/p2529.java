import java.io.*;
import java.util.*;

public class p2529 {
    static int n;
    static String[] arr;
    static boolean[] visited;
    static int[] visiting;
    static StringBuilder the_min = new StringBuilder();
    static StringBuilder the_max = new StringBuilder();

    public static void main(String[] args) throws IOException {
        input();
        sol(0);
        System.out.println(the_max);
        System.out.println(the_min);
    }
    static boolean check() {
        for (int i = 0; i < n; i++) {
            if (arr[i].equals("<")) {
                if (visiting[i] > visiting[i + 1]) return false;
            } else {
                if (visiting[i] < visiting[i + 1]) return false;
            }
        }
        return true;
    }
    static void sol(int cnt) {
        if (cnt == n + 1) {
            if(check()) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < n + 1; i++) {
                    sb.append(visiting[i]);
                }
                if (the_min.compareTo(sb) > 0) {
                    the_min = sb;
                }
                if (the_max.compareTo(sb) < 0) {
                    the_max = sb;
                }
            }
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (visited[i] == false) {
                visited[i] = true;
                visiting[cnt] = i;
                sol(cnt + 1);
                visited[i] = false;
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        arr = new String[n];
        visited = new boolean[10];
        visiting = new int[n + 1];
        for (int i = 0; i < n + 1; i++) {
            the_min.append("9");
            the_max.append("0");
        }
        line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        for (int i = 0; i < n; i++) {
            arr[i] = st.nextToken();
        }
    }
}
