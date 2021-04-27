import java.io.*;
import java.util.*;

public class Main {
    static int n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken());

        PriorityQueue<Integer> q = new PriorityQueue<>((a, b) -> b - a);
        Info[] jewel = new Info[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            jewel[i] = new Info(Integer.valueOf(st.nextToken()), Integer.valueOf(st.nextToken()));
        }
        int[] bags = new int[k];
        for (int i = 0; i < k; i++) {
            bags[i] = Integer.valueOf(br.readLine());
        }
        Arrays.sort(jewel, (a, b) -> {
            if (a.m == b.m) {
                return a.v - b.v;
            }
            return a.m - b.m;
        });
        Arrays.sort(bags);
        int j = 0;
        long ans = 0;
        for (int i = 0; i < k; i++) {
            int now_bag_m = bags[i];
            while (j < n && jewel[j].m <= now_bag_m) {
                q.add(jewel[j].v);
                j += 1;
            }
            if (!q.isEmpty()) {
                ans += q.remove();
            }
        }

        System.out.println(ans);
    }
    static class Info {
        int m, v;
        Info(int m, int v) {this.m=m; this.v=v;}
    }
}
