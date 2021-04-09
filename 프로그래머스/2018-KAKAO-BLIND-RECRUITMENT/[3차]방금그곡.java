import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Solution solution = new Solution();
        String m = "ABC";
        String[] musicinfos = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"};
        System.out.println(solution.solution(m, musicinfos));
    }
    static class Solution {
        public String solution(String m, String[] musicinfos) {
            String answer = "";
            int max_time = -1;
            for (String musicinfo : musicinfos) {
                String[] infos = musicinfo.split(",");
                int time = getTime(infos[0], infos[1]);
                String melody = getMelody(infos[3], time);
                for (int i = 0; i <= melody.length() - m.length(); i++) {
                    boolean match = true;
                    for (int j = i; j < i + m.length(); j++) {
                        if (melody.charAt(j) != m.charAt(j - i)) {
                            match = false;
                            break;
                        }
                    }
                    if (match) {
                        if (i + m.length() < melody.length() && melody.charAt(i + m.length()) == '#') continue;
                        if (max_time < time) {
                            max_time = time;
                            answer = infos[2];
                        }
                        break;
                    }
                }
            }
            if (max_time == -1) return "(None)";
            return answer;
        }

        private String getMelody(String info, int time) {
            ArrayList<String> list = new ArrayList<>();
            while (true) {
                for (int i = 0; i < info.length(); i++) {
                    if (info.charAt(i) == '#') continue;
                    if (i < info.length() - 1 && info.charAt(i + 1) == '#') {
                        list.add(info.substring(i, i + 2));
                    } else {
                        list.add(info.charAt(i) + "");
                    }
                    if (list.size() == time) break;
                }
                if (list.size() == time) break;
            }
            StringBuilder sb = new StringBuilder();
            for(String s : list) {
                sb.append(s);
            }
            return sb.toString();
        }

        private int getTime(String s, String e) {
            int ans = 0;
            int s_h = Integer.valueOf(s.substring(0, 2));
            int s_m = Integer.valueOf(s.substring(3, 5));
            int e_h = Integer.valueOf(e.substring(0, 2));
            int e_m = Integer.valueOf(e.substring(3, 5));
            ans += (e_m - s_m);
            if (e_m - s_m < 0) {
                e_h -= 1;
                ans += 60;
            }
            ans += 60 * (e_h - s_h);
            return ans;
        }
    }
}
