import java.util.*;
class Solution {
    public String solution(int[] numbers) {
        List<String> list = new ArrayList<>();
        int zeroNum = 0;
        for (int number : numbers) {
            list.add(number+"");
            zeroNum = number == 0 ? zeroNum + 1 : zeroNum;
        }
        if (zeroNum == numbers.length) {
            return "0";
        }
        list.sort((a, b) -> {
            return (b + a).compareTo(a + b);
        });
        StringBuilder ans = new StringBuilder();
        for (String now : list) {
            ans.append(now);
        }
        return ans.toString();
    }
}
