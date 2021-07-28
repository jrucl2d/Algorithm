import java.util.*;
class Solution {
    public int solution(int[] people, int limit) {
        int n = people.length;
        Arrays.sort(people);
        int r = n - 1, l = 0, ans = 0;
        while (true) {
            if (l > r) break;
            if (people[r] + people[l] <= limit) {
                ans += 1;
                l += 1;
                r -= 1;
            } else {
                ans += 1;
                r -= 1;
            }
        }
        return ans;
    }
}
