import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        PriorityQueue<Integer> min = new PriorityQueue<>();
        PriorityQueue<Integer> max = new PriorityQueue<>((a, b) -> b - a);
        StringTokenizer st = null;
        for (String s : operations) {
            st = new StringTokenizer(s);
            String op = st.nextToken();

            int num = Integer.parseInt(st.nextToken());
            if (op.equals("I")) {
                min.add(num);
                max.add(num);
            } else {
                if (min.size() == 0) continue;
                int removed;
                if (num < 0) {
                    removed = min.remove();
                    max.remove(removed);
                } else {
                    removed = max.remove();
                    min.remove(removed);
                }
            }
        }
        if (min.size() == 1) {
            int ans = min.remove();
            return new int[] {ans, ans};
        } else if (min.size() > 1) {
            return new int[] {max.remove(), min.remove()};
        } else {
            return new int[] {0, 0};
        }
    }
}
