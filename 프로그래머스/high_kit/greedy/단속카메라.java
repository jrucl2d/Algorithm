import java.util.*;
class Solution {
    public int solution(int[][] routes) {
        int n = routes.length;
        Arrays.sort(routes, (a, b) -> a[1] - b[1]);
        int loc = routes[0][1];
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (routes[i][0] > loc || loc > routes[i][1]) {
                ans += 1;
                loc = routes[i][1];
            }
        }
        return ans;
    }
}
