import java.util.*;
class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        List<Integer> list = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < dartResult.length(); i++) {
            if (dartResult.charAt(i) >= '0' && dartResult.charAt(i) <= '9') {
                sb.append(dartResult.charAt(i));
                continue;
            }
            if (dartResult.charAt(i) == '*') {
                list.set(list.size() - 1, list.get(list.size() - 1) * 2);
                if (list.size() != 1) {
                    list.set(list.size() - 2, list.get(list.size() - 2) * 2);
                }
                continue;
            }
            if (dartResult.charAt(i) == '#') {
                list.set(list.size() - 1, list.get(list.size() - 1) * -1);
                continue;
            }
            int the_num = Integer.valueOf(sb.toString());
            if (dartResult.charAt(i) == 'S') {
                list.add(the_num);
            }
            else if (dartResult.charAt(i) == 'D') {
                list.add(the_num * the_num);
            }
            else {
                list.add(the_num * the_num * the_num);
            }
            sb = new StringBuilder();
        }
        for (Integer i : list) {
            answer += i;
        }
        return answer;
    }
}