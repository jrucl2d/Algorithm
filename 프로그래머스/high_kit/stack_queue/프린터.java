import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int n = priorities.length;
        Queue<Info> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            q.add(new Info(i, priorities[i]));
        }
        Arrays.sort(priorities);
        int ans = 1;
        int pIndex = n - 1;
        while (!q.isEmpty()) {
            Info now = q.peek();
            if (now.prio < priorities[pIndex]) {
                q.add(q.remove());
            } else {
                if (location == now.first) break;
                ans += 1;
                pIndex -= 1;
                q.remove();
            }
        }
        return ans;
    }
    class Info {
        int first, prio;
        Info(int a, int b) {first = a; prio = b;}
    }
}
