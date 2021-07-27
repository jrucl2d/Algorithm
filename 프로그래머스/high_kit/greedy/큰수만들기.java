class Solution {
    public String solution(String number, int k) {
        int n = number.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int bet = i + 1;
            while (bet < n && number.charAt(i) >= number.charAt(bet)) bet += 1;
            if (bet - i <= k) {
                k -= 1;
                continue;
            }
            sb.append(number.charAt(i));
        }
        return sb.toString();
    }
}
