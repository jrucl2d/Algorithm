import java.util.*;

class Solution {
    final static int HIT = 1;
    final static int MISS = 5;
    public int solution(int cacheSize, String[] cities) {
        Map<String, Integer> map = new HashMap<>();
        int ans = 0;
        for (String city : cities) {
            if (cacheSize == 0) {
                ans += 5;
                continue;
            }
            city = city.toLowerCase();
            if (map.containsKey(city)) {
                ans += HIT;
                map.put(city, 0);
            }
            else if (map.size() < cacheSize) {
                ans += MISS;
                map.put(city, 0);
            }
            else {
                String LRU = "";
                int the_max = Integer.MIN_VALUE;
                for (String s : map.keySet()) {
                    if (the_max < map.get(s)) {
                        the_max = map.get(s);
                        LRU = s;
                    }
                }
                ans += MISS;
                map.remove(LRU);
                map.put(city, 0);
            }
            for (String s : map.keySet()) {
                map.put(s, map.get(s) + 1);
            }
        }
        return ans;
    }
}
