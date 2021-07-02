import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        Map<String, Boolean> map = new HashMap<>();
        for (String num : phone_book) {
            String subSt = null;
            for (int i = 0; i < num.length(); i++) {
                subSt = num.substring(0, i);
                if (map.containsKey(subSt)) return false;
            }
            map.put(num, true);
        }
        return true;
    }
}
