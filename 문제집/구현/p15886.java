import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class p15886 {
    static int n;
    static int[] parent;
    static String arr;

    public static void main(String[] args) throws IOException {
        input();
        sol();
        print();
    }
    static void print() {
        int ans = 1;
        int now = parent[1];
        for (int i = 1; i < parent.length; i++) {
            if (now != parent[i]) {
                now = parent[i];
                ans += 1;
            }
        }
        System.out.println(ans);
    }
    static void sol() {
        for(int i = 0; i < n; i++) {
            if (arr.charAt(i) == 'E') {
                union(i + 1, i + 2);
            } else {
                union(i, i + 1);
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr = br.readLine();
        parent = new int[n + 1];
        for(int i = 1; i < n + 1; i++) {
            parent[i] = i;
        }
    }
    static int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a < b) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
}
