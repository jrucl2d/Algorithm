import java.util.*;

class Solution {
    public long[] solution(long k, long[] room_number) {
        int n = room_number.length;
        long[] answer = new long[n];
        Map<Long, Long> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            long now = room_number[i];
            answer[i] = find(now, map);
        }
        return answer;
    }
    long find(long now, Map<Long, Long> map) {
        long next = now;
        if (map.containsKey(now)) {
            next = find(map.get(now), map);
            map.put(now, next);
            return next;
        }
        map.put(now, now + 1);
        return next;
    }
}