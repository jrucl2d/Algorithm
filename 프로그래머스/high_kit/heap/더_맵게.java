import java.util.*;
class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int sc : scoville) {
            pq.add(sc);
        }
        int ans = 0;
        while (!pq.isEmpty()) {
            if (pq.size() == 1) {
                int last = pq.peek();
                if (last < K) return -1;
            }
            if (pq.peek() >= K) {
                break;
            }
            if (pq.size() >= 2) {
                int last = pq.remove();
                int last_before = pq.remove();
                pq.add(last + last_before * 2);
            }
            ans += 1;
        }
        return ans;
    }
}
