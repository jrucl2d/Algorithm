import java.util.*;
class Solution {
    int INF = 10000000;
    int n;
    boolean[] noSosu = new boolean[INF];
    Set<Integer> set = new HashSet<>();
    boolean[] visited;
    int[] visiting;
    int ans = 0;
    
    public int solution(String numbers) {
        init();
        n = numbers.length();
        for (int l = 1; l <= n; l++) {
            visited = new boolean[n];
            visiting = new int[n];
            dfs(l, 0, numbers);
        }
        return ans;
    }
    void dfs(int l, int index, String s) {
        if (l == index) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < l; i++) sb.append(visiting[i]);
            int val = Integer.parseInt(sb.toString());
            if (!noSosu[val] && set.add(val)) {
                ans += 1;
            }
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            visiting[index] = s.charAt(i) - '0';
            dfs(l, index + 1, s);
            visited[i] = false;
        }
    }
    void init() {
        noSosu[0] = noSosu[1] = true;
        for (int i = 4; i < INF; i++) {
            for (int j = 2; j <= (int)Math.sqrt(i); j++) {
                if (i % j == 0) {
                    noSosu[i] = true;
                    break;
                }
            }
        }
    }
}
