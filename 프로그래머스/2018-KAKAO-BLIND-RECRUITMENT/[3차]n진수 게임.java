class Solution {
    public String solution(int n, int t, int m, int p) {
        StringBuilder sb = new StringBuilder();
        StringBuilder ans = new StringBuilder();
        int ans_cnt = 0;

        int now_index = 0;
        int now_number = 0;
        while (true) {
            if (now_index >= sb.length() - 1) {
                sb.append(toNary(now_number++, n));
            }
            if (now_index % m == p - 1) {
                ans.append(sb.charAt(now_index));
                ans_cnt += 1;
            }
            if (ans_cnt == t) break;
            now_index += 1;
        }
        return ans.toString();
    }
    String toNary(int num, int div) {
        StringBuilder sb = new StringBuilder();
        while (true) {
            int rest = num % div;
            if (rest >= 10) {
                sb.append((char)((int)'A' - 10 + rest));
            } else {
                sb.append(num % div);
            }
            num /= div;
            if (num == 0) break;
        }
        String tmp = sb.toString();
        StringBuilder ret = new StringBuilder();
        for (int i = tmp.length() - 1; i >= 0; i--) {
            ret.append(tmp.charAt(i));
        }
        return ret.toString();
    }
}