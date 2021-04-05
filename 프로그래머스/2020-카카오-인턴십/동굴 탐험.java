import java.util.*;

class Solution {
    int[] visiting;
    boolean[] visited;
    List<Integer>[] two_path;
    List<Integer>[] one_path;
    int n;
    int count = 1;
    boolean ans = true;
    
    public boolean solution(int nn, int[][] path, int[][] order) {
        n = nn;
        visiting = new int[n];
        visited = new boolean[n];
        two_path = new List[n];
        one_path = new List[n];
        for (int i = 0; i < n; i++) {
            two_path[i] = new ArrayList<>();
            one_path[i] = new ArrayList<>();
        }
        for (int[] ints : order) {
            if (ints[1] == 0) return false;
            one_path[ints[0]].add(ints[1]);
        }
        for (int[] ints : path) {
            two_path[ints[0]].add(ints[1]);
            two_path[ints[1]].add(ints[0]);
        }
        // 양방향 그래프 -> 단방향 그래프
        Queue<Integer> q = new LinkedList<>();
        boolean[] two_visited = new boolean[n];
        q.add(0);
        two_visited[0] = true;
        while (!q.isEmpty()) {
            int now = q.remove();
            for (int i = 0; i < two_path[now].size(); i++) {
                int next = two_path[now].get(i);
                if (two_visited[next]) continue;
                one_path[now].add(next);
                two_visited[next] = true;
                q.add(next);
            }
        }
        dfs(0);
        return ans;
    }
    void dfs(int now) {
        if (ans == false) return;
        visiting[now] = count++;
        for (int i = 0; i < one_path[now].size(); i++) {
            int next = one_path[now].get(i);
            if (visiting[next] == 0) dfs(next);
            else if (!visited[next]){
                ans = false;
                return;
            }
        }
        visited[now] = true;
    }
}
