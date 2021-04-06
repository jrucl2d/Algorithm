import java.util.*;
class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        List<String> a1 = new ArrayList<>(n);
        List<String> a2 = new ArrayList<>(n);
        for (int a : arr1) {
            a1.add(toBinary(a, n));
        }
        for (int a : arr2) {
            a2.add(toBinary(a, n));
        }
        StringBuilder sb;
        String[] ans = new String[n];
        int index = 0;
        for (int i = 0; i < n; i++) {
            sb = new StringBuilder();
            for (int j = n - 1; j >= 0; j--) {
                int the_sum = (int)a1.get(i).charAt(j) + (int)a2.get(i).charAt(j) - (int)'0' * 2;
                if (the_sum == 0) {
                    sb.append(" "); continue;
                }
                sb.append("#");
            }
            ans[index++] = sb.toString();
        }
        return ans;
    }
    String toBinary(int a, int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(a % 2);
            a /= 2;
        }
        return sb.toString();
    }
}