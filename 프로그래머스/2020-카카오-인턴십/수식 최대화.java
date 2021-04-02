class Solution {
    boolean[] ops_existing = new boolean[3];
    int ops_existing_cnt = 0;
    int[] visiting;
    boolean[] visited = new boolean[3];
    long ans = Long.MIN_VALUE;
    
    public long solution(String expression) {
        for (int i = 0; i < expression.length(); i++) {
            if (expression.charAt(i) == '-') ops_existing[0] = true;
            else if (expression.charAt(i) == '+') ops_existing[1] = true;
            else if (expression.charAt(i) == '*') ops_existing[2] = true;
        }
        for (boolean b : ops_existing) {
            if (b) ops_existing_cnt += 1;
        }
        visiting = new int[ops_existing_cnt];
        dfs(0, expression);
        return ans;
    }
    void dfs(int index, String expression) {
        if (index == ops_existing_cnt) {
            ans = Math.max(ans, Math.abs(calc(expression, 0)));
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (ops_existing[i] && !visited[i]) {
                visiting[index] = i;
                visited[i] = true;
                dfs(index + 1, expression);
                visited[i] = false;
            }
        }
    }

    long calc(String s, int index) {
        if (index == ops_existing_cnt) {
            return Long.valueOf(s);
        }
        String[] splitted;
        long inner_ans = 0;
        switch (visiting[index]) {
            case 0:
                splitted = s.split("-");
                inner_ans = calc(splitted[0], index + 1);
                for (int i = 1; i < splitted.length; i++) {
                    inner_ans -= calc(splitted[i], index + 1);
                }
                return inner_ans;
            case 1:
                splitted = s.split("\\+");
                inner_ans = 0;
                for (int i = 0; i < splitted.length; i++) {
                    inner_ans += calc(splitted[i], index + 1);
                }
                return inner_ans;
            case 2:
                splitted = s.split("\\*");
                inner_ans = 1;
                for (int i = 0; i < splitted.length; i++) {
                    inner_ans *= calc(splitted[i], index + 1);
                }
                return inner_ans;
            default:
                return 0;
        }
    }
}