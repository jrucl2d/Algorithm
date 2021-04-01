import java.util.*;
class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        int n = board.length;
        int[] heights = new int[n];
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (board[i][j] != 0) {
                    heights[j] = i;
                    break;
                }
            }
        }
        Stack<Integer> stack = new Stack<>();
        for (int move = 0; move < moves.length; move++) {
            int now = moves[move] - 1;
            if (heights[now] == n) continue;
            if (board[heights[now]][now] == 0) continue;
            if (!stack.empty() && board[heights[now]][now] == stack.get(stack.size() - 1)) {
                stack.pop();
                answer += 2;
            } else {
                stack.push(board[heights[now]][now]);
            }
            heights[now] += 1;
        }
        return answer;
    }
}