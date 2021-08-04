class Solution {
    int ans = 100;
    boolean[] visited;
    public int solution(String begin, String target, String[] words) {
        visited = new boolean[words.length];
        dfs(words, begin, target, 0);
        return ans == 100 ? 0 : ans;
    }
    void dfs(String[] words, String now, String target, int cnt) {
        if (now.equals(target)) {
            ans = Math.min(ans, cnt);
            return;
        }
        for (int i = 0; i < words.length; i++) {
            if (visited[i]) continue;
            if (canGo(words[i], now)) {
                visited[i] = true;
                dfs(words, words[i], target, cnt + 1);
                visited[i] = false;
            }
        }
    }
    boolean canGo(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) diff += 1;
            if (diff > 1) return false;
        }
        return true;
    }
}
