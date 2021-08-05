class Solution {
    int n, index = 0;
    boolean[] visited;
    StringBuilder ans = new StringBuilder();
    public String[] solution(String[][] tickets) {
        n = tickets.length;
        StringBuilder sb = new StringBuilder();
        visited = new boolean[n];
        for (int i = 0; i < n + 1; i++) ans.append("ZZZ");
        for (int i = 0; i < n; i++) {
            if (!tickets[i][0].equals("ICN")) continue;
            StringBuilder tmp = new StringBuilder();
            tmp.append("ICN").append(tickets[i][1]);
            visited[i] = true;
            dfs(2, tickets[i][1], tickets, tmp);
            visited[i] = false;
        }
        String[] ret = new String[n + 1];
        for (int i = 0; i < n + 1; i++) {
            ret[i] = ans.substring(3 * i, 3 * i + 3);
        }
        return ret;
    }
    void dfs(int index, String now, String[][] arr, StringBuilder sb) {
        if (index == n + 1) {
            if (ans.compareTo(sb) > 0) ans = sb;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!arr[i][0].equals(now)) continue;
            if (visited[i]) continue;
            visited[i] = true;
            StringBuilder tmp = new StringBuilder();
            tmp.append(sb).append(arr[i][1]);
            dfs(index + 1, arr[i][1], arr, tmp);
            visited[i] = false;
        }
    }
}
