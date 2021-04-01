import java.util.*;
class Solution {    
    public int[] solution(String s) {
        int[] answer;
        String[] group = s.split("}");
        for (int i = 0; i < group.length; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < group[i].length(); j++) {
                if (group[i].charAt(j) == '{') continue;
                if (j == 0 && group[i].charAt(j) == ',') continue;
                sb.append(group[i].charAt(j));
            }
            group[i] = sb.toString();
        }
        answer = new int[group.length];
        Arrays.sort(group, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length() - o2.length();
            }
        });
        Set<Integer> set = new HashSet<>();
        int answerIndex = 0;
        for (int i = 0; i < group.length; i++) {
            String now = group[i];
            String[] nowArr = now.split(",");
            for (int j = 0; j < nowArr.length; j++) {
                int nowInt = Integer.valueOf(nowArr[j]);
                if (!set.add(nowInt)) continue;
                answer[answerIndex++] = nowInt;
                break;
            }
        }
        return answer;
    }
}