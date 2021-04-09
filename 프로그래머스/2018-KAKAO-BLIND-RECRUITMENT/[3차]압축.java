import java.util.*;
class Solution {
    Map<String, Integer> map = new HashMap<>();
        public int[] solution(String msg) {
            List<Integer> ans = new ArrayList<>();
            for (int i = 0; i < 26; i++) {
                 map.put("" + (char)((int)'A' + i), i + 1);
            }
            int index = 27;
            StringBuilder sb = null;
            boolean end = false;
            for (int start = 0; start < msg.length(); start++) {
                if (end) break;
                sb = new StringBuilder();
                int go = start;
                while (true) {
                    sb.append(msg.charAt(go));
                    if (!map.containsKey(sb.toString())) {
                        map.put(sb.toString(), index++);
                        ans.add(map.get(sb.substring(0, sb.length() - 1)));
                        start = go - 1; // start++에 의해서 +1이 되므로
                        break;
                    }
                    if (go + 1 == msg.length()) {
                        end = true;
                        ans.add(map.get(sb.toString()));
                        break;
                    }
                    go += 1;
                }
            }
            int[] ret = new int[ans.size()];
            for (int i = 0; i < ans.size(); i++) {
                ret[i] = ans.get(i);
            }
            return ret;
        }
}