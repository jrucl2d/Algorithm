import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] ans = new int[commands.length];
        int index = 0;
        for (int[] command : commands) {
            int from = command[0] - 1;
            int to = command[1] - 1;
            int loc = command[2] - 1;
            int[] newArr = new int[to - from + 1];
            for (int i = from; i <= to; i++) {
                newArr[i - from] = array[i];
            }
            Arrays.sort(newArr);
            ans[index++] = newArr[loc];
        }
        return ans;
    }
}

