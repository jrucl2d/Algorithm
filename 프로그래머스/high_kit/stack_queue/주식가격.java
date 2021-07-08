import java.util.*;
class Solution {
    public int[] solution(int[] prices) {
        Stack<Integer> stack = new Stack<>();
        int n = prices.length;
        int[] ans = new int[n];
        stack.push(0);
        int i = 1;
        for (; i < n; i++) {    
            while (!stack.isEmpty() && (prices[stack.peek()] > prices[i])) {
                int top = stack.pop();
                ans[top] = i - top;
            }
            stack.push(i);
        }
        while (!stack.isEmpty()) {
            int top = stack.pop();
            ans[top] = i - top - 1;
        }
        return ans;
    }
}
