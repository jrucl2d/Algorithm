import java.util.*;
class Solution {
    public int solution(int[][] jobs) {
        int n = jobs.length;
        Info[] infos = new Info[n];
        int index = 0;
        for (int[] job : jobs) {
            infos[index++] = new Info(job[0], job[1]);
        }
        Arrays.sort(infos, (a, b) -> a.s - b.s);
        PriorityQueue<Info> pq = new PriorityQueue<>((a, b) -> a.du - b.du);
        int start = 0;
        int ans = 0;
        index = 0;
        while (index < n || !pq.isEmpty()) {
            // 다음 시작보다 이전에 시작하는 작업들을 큐에 넣음
            while (index < n && start >= infos[index].s) {
                pq.add(infos[index++]);
            }
            if (pq.isEmpty()) {
                // 큐가 비어있다면 다음 위치를 시작점으로 jump
                start = infos[index].s;
            } else {
                // 큐가 비어있지 않다면 큐에서 가장 짧은 시간을 뽑아서 더함
                Info now = pq.remove();
                ans += (start + now.du - now.s);
                start += now.du;
            }
        }
        return ans / n;
    }
    class Info {
        int s, du;
        Info (int s, int du) {this.s=s; this.du=du;}
    }
}
