class Solution {
    public int[] solution(int brown, int yellow) {
        int sum = (brown + 4) / 2;
        int sero = 3;
        int garo = sum - sero;
        while (true) {
            if (garo * sero == brown + yellow) break;
            sero += 1;
            garo -= 1;
        }
        int[] answer = {garo, sero};
        return answer;
    }
}
