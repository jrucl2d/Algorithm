
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Solution solution = new Solution();
        int n = Integer.valueOf(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
        int m = Integer.valueOf(br.readLine());
        int[] find = new int[m];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < m; i++) {
            find[i] = Integer.valueOf(st.nextToken());
        }
        for (int i : solution.solution(n, m, arr, find)) {
            System.out.print(i + " ");
        }
    }

    static class Solution {
        public int[] solution(int n, int m, int[] arr, int[] find) {
            int[] ans = new int[m];
            Arrays.sort(arr);
            for (int i = 0; i < m; i++) {
                ans[i] = binarySearch(arr, 0, n - 1, find[i]);
            }
            return ans;
        }

        int binarySearch(int[] arr, int l, int r, int find) {
            if (l <= r) {
                int m = (l + r) / 2;
                if (arr[m] > find) {
                    return binarySearch(arr, l, m - 1, find);
                } else if (arr[m] < find) {
                    return binarySearch(arr, m + 1, r, find);
                }
                return 1;
            }
            return 0;
        }
    }
}