import java.util.*;

class Solution {
    List<Integer>[] checked_numbers;
    Set<String> ans_set = new HashSet<>();
    int[] visited;
    
    public int solution(String[] user_id, String[] banned_id) {
        checked_numbers = new List[banned_id.length];
        visited = new int[banned_id.length];
        for (int i = 0; i < banned_id.length; i++) {
            checked_numbers[i] = new ArrayList<>();
        }
        for (int i = 0; i < banned_id.length; i++) {
            String ban_id = banned_id[i];
            for (int j = 0; j < user_id.length; j++) {
                String checking_string = user_id[j];
                if (ban_id.length() != checking_string.length()) continue;
                boolean check_no = false;
                for (int k = 0; k < checking_string.length(); k++) {
                    if (ban_id.charAt(k) == '*') continue;
                    if (ban_id.charAt(k) != checking_string.charAt(k)) {
                        check_no = true;
                        break;
                    }
                }
                if (!check_no) checked_numbers[i].add(j);
            }
        }
        dfs(0, banned_id.length);
        return ans_set.size();
    }
    void dfs(int index, int end) {
        if (index == end) {
            int[] showing = new int[visited.length];
            Set<Integer> miniSet = new HashSet<>();
            for (int i = 0; i < visited.length; i++) {
                if(!miniSet.add(visited[i])) return;
                showing[i] = visited[i];
            }
            Arrays.sort(showing);
            StringBuilder sb = new StringBuilder();
            for (int i : showing) {
                sb.append(i);
            }
            ans_set.add(sb.toString());
            return;
        }
        for (int i = 0; i < checked_numbers[index].size(); i++) {
            visited[index] = checked_numbers[index].get(i);
            dfs(index + 1, end);
        }
    }
}