import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        int[] one = {1, 2, 3, 4, 5}; // 5
        int[] two = {2, 1, 2, 3, 2, 4, 2, 5}; // 8
        int[] three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 10
        int oneIndex = 0, twoIndex = 0, threeIndex = 0;
        int[] correct = new int[3];
        for (int ans : answers) {
            if (one[oneIndex] == ans) correct[0] += 1;
            if (two[twoIndex] == ans) correct[1] += 1;
            if (three[threeIndex] == ans) correct[2] += 1;
            
            oneIndex = (oneIndex + 1) % 5;
            twoIndex = (twoIndex + 1) % 8;
            threeIndex = (threeIndex + 1) % 10;
        }
        int max = Math.max(Math.max(correct[0], correct[1]), correct[2]);
        
        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            if (correct[i] == max) answer.add(i + 1);
        }
        int[] ret = new int[answer.size()];
        for (int i = 0; i < answer.size(); i++) {
            ret[i] = answer.get(i);
        }
        return ret;
    }
}
