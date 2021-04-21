import java.io.*;
import java.util.*;

public class Main {
    static int n, m;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        line = br.readLine();
        m = Integer.valueOf(line);
        line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");

        List<Info> q = new ArrayList<>();
        int now;
        for (int i = 0; i < m; i++) {
            now = Integer.valueOf(st.nextToken());
            boolean exist = false;
            for (int j = 0; j < q.size(); j++) {
                if (q.get(j).num == now) {
                    q.get(j).count += 1;
                    exist = true;
                    break;
                }
            }
            if (exist) continue;
            if (q.size() < n) {
                q.add(new Info(now, i));
                continue;
            }
            q.sort((a, b) -> {
                if (a.count == b.count) {
                    return b.time - a.time;
                }
                return b.count - a.count;
            });
            q.remove(n - 1);
            q.add(new Info(now, i));
        }
        q.sort((a, b) -> a.num - b.num);
        for (Info info : q) {
            System.out.print(info.num + " ");
        }
    }
    static class Info {
        int num, time, count;
        Info(int num, int time) {this.num = num; this.time=time;this.count=1;}
    }
}