class Solution {
    public int solution(int[] stones, int k) {
        int the_max = -1;
        for (int stone : stones) {
            the_max = Math.max(the_max, stone);
        }
        return binary_search(stones, 0, the_max, k);
    }
    int binary_search(int[] stones, int start, int end, int k) {
        if (start <= end) {
            int[] tmp = new int[stones.length];
            System.arraycopy(stones, 0, tmp, 0, stones.length);
            int mid = (start + end) / 2;
            int zero_continue = 0;
            int zero_continue_max = -1;
            for (int i = 0; i < tmp.length; i++) {
                tmp[i] -= mid;
                if (tmp[i] <= 0) {
                    zero_continue += 1;
                } else {
                    zero_continue = 0;
                }
                zero_continue_max = Math.max(zero_continue, zero_continue_max);
            }
            if (zero_continue_max >= k) {
                return binary_search(stones, start, mid - 1, k);
            }
            return binary_search(stones, mid + 1, end, k);
        }
        return start;
    }
}