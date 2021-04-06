import java.util.*;

class Solution {
    static final int MULT = 65536;
    public int solution(String str1, String str2) {
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        List<String> list1 = getShorts(str1);
        List<String> list2 = getShorts(str2);
        if (list1.size() == 0 && list2.size() == 0) return MULT;
        Map<String, Integer> map1 = new HashMap<>();
        for (String s : list1) {
            if (map1.containsKey(s)) {
                map1.put(s, map1.get(s) + 1);
                continue;
            }
            map1.put(s, 1);
        }
        Map<String, Integer> map2 = new HashMap<>();
        for (String s : list2) {
            if (map2.containsKey(s)) {
                map2.put(s, map2.get(s) + 1);
                continue;
            }
            map2.put(s, 1);
        }
        
        int interaction = getInteraction(map1, map2);
        int union = getUnion(map1, map2);
        double d_ans = (double)interaction / union;
        int ans = (int)(d_ans * MULT);
        return ans;
    }
    int getUnion(Map<String, Integer> m1, Map<String, Integer> m2) {
        for (String s : m2.keySet()) {
            if (m1.containsKey(s)) {
                m1.put(s, Math.max(m1.get(s), m2.get(s)));
                continue;
            }
            m1.put(s, m2.get(s));
        }
        int ret = 0;
        for (String s : m1.keySet()) {
            ret += m1.get(s);
        }
        return ret;
    }
    int getInteraction(Map<String, Integer> m1, Map<String, Integer> m2) {
        int ret = 0;
        for (String s : m2.keySet()) {
            if (m1.containsKey(s)) {
                ret += Math.min(m1.get(s), m2.get(s));
            }
        }
        return ret;
    }
    List<String> getShorts(String s) {
        List<String> list = new ArrayList<>();
        for (int i = 0; i < s.length() - 1; i++) {
            String subStr = s.substring(i, i + 2);
            if (subStr.charAt(0) >= 'a' && subStr.charAt(0) <= 'z' && 
               subStr.charAt(1) >= 'a' && subStr.charAt(1) <= 'z') {
                list.add(subStr);
            }
        }
        return list;
    }
}