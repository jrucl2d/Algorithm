import java.io.*;
import java.util.*;

public class Main {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        PriorityQueue<Integer> max = new PriorityQueue<>();
        PriorityQueue<Integer> min = new PriorityQueue<>((a, b) -> b - a);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int now = Integer.valueOf(br.readLine());
            if (min.size() == max.size()) {
                min.add(now);
            } else {
                max.add(now);
            }
            if (max.size() == 0) {
                sb.append(min.peek() + "\n");
                continue;
            }
            int max_top = max.peek();
            int min_top = min.peek();
            if (max_top < min_top) {
                min.remove();
                max.remove();
                min.add(max_top);
                max.add(min_top);
            }
            sb.append(min.peek() + "\n");
        }
        System.out.println(sb);
    }
}
