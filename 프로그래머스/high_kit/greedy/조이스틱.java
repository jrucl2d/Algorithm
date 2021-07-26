class Solution {
    public int solution(String name) {
        int ans = 0;
        int n = name.length();
        
        int move = n - 1;
        
        for (int i = 0; i < n; i++) {
            ans += getVal(name.charAt(i));
            
            int noA = i + 1;
            while (noA < n && name.charAt(noA) == 'A') noA += 1;
            
            move = Math.min(move, (i * 2) + (n - noA));
        }
        return ans + move;
    }
    int getVal(char now) {
        int first = (int)now - (int)'A';
        int second = 26 - first;
        return Math.min(first, second);
    }
}
