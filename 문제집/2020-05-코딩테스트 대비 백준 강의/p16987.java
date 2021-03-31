import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static Egg[] arr;
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        input();
        sol(0, arr);
        System.out.println(ans);
    }
    static void sol(int index, Egg[] arr) {
        if (index == n) {
            int inner_ans = 0;
            for (Egg egg : arr) {
                if (egg.hard <= 0) inner_ans += 1;
            }
            ans = Math.max(ans, inner_ans);
            return;
        }
        Egg now = arr[index];
        boolean not_broken = false;
        if (now.hard <= 0) {
            sol(index + 1, arr);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (i == index) continue;
            Egg other = arr[i];
            if (other.hard > 0) {
                not_broken = true;
                toggle(arr, index, i, true);
                sol(index + 1, arr);
                toggle(arr, index, i, false);
            }
        }
        if (!not_broken) {
            sol(index + 1, arr);
        }
    }
    static void toggle(Egg[] arr, int a, int b, boolean hit) {
        if (hit) {
            arr[a].hard -= arr[b].weight;
            arr[b].hard -= arr[a].weight;
        } else {
            arr[a].hard += arr[b].weight;
            arr[b].hard += arr[a].weight;
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        arr = new Egg[n];
        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            arr[i] = new Egg();
            arr[i].hard = Integer.valueOf(st.nextToken());
            arr[i].weight = Integer.valueOf(st.nextToken());
        }
    }
    static class Egg {
        int hard;
        int weight;
    }
}
