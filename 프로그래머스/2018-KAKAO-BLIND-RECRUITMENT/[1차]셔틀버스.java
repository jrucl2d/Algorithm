import java.util.*;
class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        int[] times = new int[timetable.length];
        int t_index = 0;
        for (String timet : timetable) {
            times[t_index++] = Integer.valueOf(timet.split(":")[0]) * 60 + Integer.valueOf(timet.split(":")[1]);
        }
        Arrays.sort(times);
        int go_time = 540;
        int now_index = 0;
        int the_max = m;

        for (int iter = 0; iter < n; iter++) {
            the_max = m;
            for (int i = now_index; i < times.length; i++) {
                if (times[i] <= go_time) {
                    now_index += 1;
                    the_max -= 1;
                    if (the_max == 0) break;
                }
            }
            if (iter == n - 1) {
                if (the_max == 0) {
                    // 마지막 버스, 자리 없음
                    return timeToString(times[now_index - 1] - 1); // 마지막 사람 바로 직전 시간
                }
                else {
                    return timeToString(go_time);
                }
            }
            go_time += t;
            if (go_time >= 60 * 24) break; // 23:39 이상이면 해산
        }
        return "";
    }
    String timeToString(int num) {
        int hour = num / 60;
        int minute = num % 60;
        String ans = "";
        if (hour < 10) ans += 0;
        ans += hour;
        ans += ":";
        if (minute < 10) ans += 0;
        ans += minute;
        return ans;
    }
}