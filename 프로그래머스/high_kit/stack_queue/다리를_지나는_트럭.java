import java.util.*;
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        Queue<Integer> q = new LinkedList<>();
        int ans = 0;
        int sum = 0;
        for (int truck : truck_weights) {
            while (true) {
                if (q.isEmpty()) {
                    q.add(truck);
                    ans += 1;
                    sum += truck;
                    break;
                } else if (q.size() == bridge_length) {
                    // 도착
                    sum -= q.remove();
                } else {
                    if (sum + truck <= weight) {
                        q.add(truck);
                        sum += truck;
                        ans += 1;
                        break;
                    } else {
                        q.add(0);
                        ans += 1;
                    }
                }
            }
        }
        return ans + bridge_length; // 마지막 트럭이 이동하기 위한 시간 bridge_length를 더해줌
    }
}
