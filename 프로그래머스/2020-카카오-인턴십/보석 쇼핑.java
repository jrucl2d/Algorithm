import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        Set<String> the_set = new HashSet<>();
        for (String gem : gems) {
            the_set.add(gem);
        }
        int n = the_set.size();
        int[] ans = new int[] {0, 0};
        Map<String, Integer> map = new HashMap<>();
        int s = 0, e = 0;
        int the_len = Integer.MAX_VALUE;
        while (true) {
            if (map.size() < n && e < gems.length) {
                if (map.containsKey(gems[e])) {
                    map.put(gems[e], map.get(gems[e]) + 1);
                } else {
                    map.put(gems[e], 1);
                }
                e += 1;
            } else {
                if (map.size() == n) {
                    int inner_len = e - s;
                    if (inner_len < the_len) {
                        the_len = inner_len;
                        ans[0] = s + 1; ans[1] = e;
                    }
                }
                map.put(gems[s], map.get(gems[s]) - 1);
                if (map.get(gems[s]) == 0) {
                    map.remove(gems[s]);
                }
                s += 1;
                if (s == gems.length) break;
            }
        }
        return ans;
    }
}