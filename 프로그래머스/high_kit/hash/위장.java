import java.util.*;
class Solution {
    int ans = 0;
    public int solution(String[][] clothes) {
        Map<String, Integer> map = new HashMap<>();
        for (String[] cloth : clothes) {
            if (map.containsKey(cloth[1])) map.put(cloth[1], map.get(cloth[1]) + 1);
            else map.put(cloth[1], 1);
        }
        int ans = 1;
        for (String key : map.keySet()) {
            ans *= (map.get(key) + 1);
        }
        ans -= 1;
        
        return ans;
    }
}
