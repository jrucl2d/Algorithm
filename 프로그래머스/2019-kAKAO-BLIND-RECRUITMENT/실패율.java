import java.util.*;
class Solution {
    public int[] solution(int N, int[] stages) {
            int[] answer = new int[N];
            Info[] tmpAnswer = new Info[N];
            int peopleCount = stages.length;
            Arrays.sort(stages);
            int index = 0;
            for (int i = 1; i <= N; i++) {
                int count = 0;
                for (; index < stages.length; index++) {
                    if (i != stages[index]) break;
                    count += 1;
                }
                double val = peopleCount == 0 ? 0 : (double) count / peopleCount;
                tmpAnswer[i - 1] = new Info(val, i);
                peopleCount -= count;
            }
            Arrays.sort(tmpAnswer, (a, b) -> {
                if (a.val == b.val) return a.stage - b.stage;
                if (b.val > a.val) return 1;
                return -1;
            });
            for (int i = 0; i < N; i++) {
                answer[i] = tmpAnswer[i].stage;
            }
            return answer;
        }
        class Info {
            double val;
            int stage;
            Info(double a, int b) {val=a;stage=b;}
        }
}