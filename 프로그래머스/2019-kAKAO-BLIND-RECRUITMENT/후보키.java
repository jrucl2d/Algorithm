import java.util.*;
class Solution {
    int[] visiting = new int[8];
        boolean[] visited = new boolean[8];
        String[][] rel;
        List<String> ans = new ArrayList<>();
        int c;
        public int solution(String[][] relation) {
            c = relation[0].length;
            rel = relation;
            for (int i = 1; i <= c; i++) {
                dfs(i, 0, 0);
            }
            return ans.size();
        }
        private void dfs(int end, int index, int start) {
            if (index == end) {
                Set<String> set = new HashSet<>();
                StringBuilder key;
                for (int i = 0; i < rel.length; i++) {
                    key = new StringBuilder();
                    for (int j = 0; j < end; j++) {
                        key.append(rel[i][visiting[j]]);
                    }
                    if (!set.add(key.toString())) return;
                }
                StringBuilder index_key = new StringBuilder();
                boolean[] have = new boolean[9];
                for (int i = 0; i < end; i++) {
                    index_key.append(visiting[i]);
                    have[visiting[i]] = true;
                }
                for (int i = 0; i < ans.size(); i++) {
                    String now = ans.get(i);
                    boolean all_true = true;
                    for (int j = 0; j < now.length(); j++) {
                        if (!have[(int)now.charAt(j) - (int)'0']) {
                            all_true = false; break;
                        }
                    }
                    if (all_true) return;
                }
                ans.add(index_key.toString());
                return;
            }
            for (int i = start; i < c; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    visiting[index] = i;
                    dfs(end, index + 1, i + 1);
                    visited[i] = false;
                }
            }
        }
}