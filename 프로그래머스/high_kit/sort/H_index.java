import java.util.*;
class Solution {
    public int solution(int[] citations) {
        Arrays.sort(citations);
        
        int n = citations.length;
        int ans = 0;
        for (int h = 0; h <= citations[n - 1]; h++) {
            int loc = lower_bound(citations, 0, n - 1, h);
            int over = n - loc;
            if (over >= h && loc <= h) ans = h;
        }
        return ans;
    }
    int lower_bound(int[] arr, int l, int r, int v) {
        if (l < r) {
            int m = (l + r) / 2;
            if (arr[m] >= v) {
                return lower_bound(arr, l, m, v);
            } else {
                return lower_bound(arr, m + 1, r, v);
            }
        }
        return r;
    }
}
