
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Solution solution = new Solution();
        int n = Integer.valueOf(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] arr = new int[n];
        int max_value = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
            max_value = Math.max(max_value, arr[i]);
        }
        int total = Integer.valueOf(br.readLine());
        System.out.println(solution.solution(arr, total, max_value));
    }

    static class Solution {
        int ans = -1;
        public int solution(int[] arr, int total, int max_value) {
            binarySearch(arr, 0, max_value, total);
            return ans;
        }
        void binarySearch(int[] arr, int l, int r, int total) {
            if (l <= r) {
                int m = (l + r) / 2;
                int sum = 0;
                for (int i = 0; i < arr.length; i++) {
                    if (arr[i] > m) {
                        sum += m;
                        continue;
                    }
                    sum += arr[i];
                }
                if (sum <= total) {
                    ans = Math.max(m, ans);
                    binarySearch(arr, m + 1, r, total);
                } else if (sum > total) {
                    binarySearch(arr, l, m - 1, total);
                }
            }
        }
    }
}