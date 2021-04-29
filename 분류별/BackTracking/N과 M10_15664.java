import java.io.*;
import java.util.*;

public class Main {
    static int n, m ;
    static int[] arr;
    static int[] visiting = new int[10];
    static boolean[] visited = new boolean[10001];
    static StringBuilder sb = new StringBuilder();
    static Set<String> set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
        Arrays.sort(arr);
        dfs(0, 0);
        System.out.println(sb);
    }
    static void dfs(int index, int start) {
        if (index == m) {
            StringBuilder now = new StringBuilder();
            for (int i = 0; i < m; i++) {
                now.append(visiting[i] + " ");
            }
            if(set.add(now.toString())) {
                sb.append(now + "\n");
            }
            return;
        }
        for (int i = start; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            visiting[index] = arr[i];
            dfs(index + 1, i + 1);
            visited[i] = false;
        }
    }
}
