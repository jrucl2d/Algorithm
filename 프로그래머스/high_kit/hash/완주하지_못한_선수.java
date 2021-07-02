import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> map = new HashMap<>();
        for (String name : participant) {
            if (map.containsKey(name)) {
                map.put(name, map.get(name) + 1);
            } else {
                map.put(name, 1);
            }
        }
        for (String name : completion) {
            int count = map.get(name);
            if (count == 1) map.remove(name);
            else map.put(name, count - 1);
        }
        for(String now : map.keySet()) return now;
        return "";
    }
}
