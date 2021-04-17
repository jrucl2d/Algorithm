import java.io.*;
import java.util.*;

public class Main {
    static int t, n, k, w;
    static int[] time, dp;
    static Info[] info;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        sb = new StringBuilder();
        input();
        System.out.println(sb);
    }

    static void sol() {
        PriorityQueue<Info> q = new PriorityQueue<>((a, b) -> a.income - b.income);
        for (int i = 1; i <= n; i++) {
            if (info[i].income == 0) {
                dp[info[i].num] = time[info[i].num];
                q.add(info[i]);
            }
        }
        while (!q.isEmpty()) {
            Info now = q.remove();
            for (int i = 0; i < now.out.size(); i++) {
                int next = now.out.get(i);
                info[next].income -= 1;
                dp[next] = Math.max(dp[next], time[next] + dp[now.num]);
                if (info[next].income == 0)
                    q.add(info[next]);
            }
        }
        sb.append(dp[w] + "\n");
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.valueOf(br.readLine());
        for (int i = 0; i < t; i++) {
            String line = br.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            n = Integer.valueOf(st.nextToken());
            k = Integer.valueOf(st.nextToken());
            time = new int[n + 1];
            dp = new int[n + 1];
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 1; j <= n; j++) {
                time[j] = Integer.valueOf(st.nextToken());
            }
            info = new Info[n + 1];
            for (int j = 0; j <= n; j++)
                info[j] = new Info(j);
            int aa, bb;
            for (int j = 0; j < k; j++) {
                line = br.readLine();
                st = new StringTokenizer(line, " ");
                aa = Integer.valueOf(st.nextToken());
                bb = Integer.valueOf(st.nextToken());
                info[bb].income += 1;
                info[aa].out.add(bb);
            }
            w = Integer.valueOf(br.readLine());
            sol();
        }
    }

    static class Info {
        int num, income;
        List<Integer> out;

        Info(int num) {
            this.num = num;
            income = 0;
            out = new ArrayList<>();
        }
    }
}