import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int n = progresses.length;
        int[] remain = new int[n];
        for (int i = 0; i < n; i++) {
            int minus = 100 - progresses[i];
            remain[i] = minus % speeds[i] == 0 ? minus / speeds[i] : minus / speeds[i] + 1;
        }
        List<Integer> ans = new ArrayList<>();
        int num = remain[0];
        int count = 1;
        int now = 0;
        for (int i = 1; i < n; i++) {
            now = remain[i];
            if (now <= num) {
                count += 1;
            } else {
                ans.add(count);
                num = now;
                count = 1;
            }
        }
        if (now <= num) ans.add(count);
        int[] ret = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            ret[i] = ans.get(i);
        }
        return ret;
    }
}
