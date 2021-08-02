class Solution {
    int ans = 0;
    public int solution(int[] numbers, int target) {
        dfs(numbers, 0, 0, target);
        return ans;
    }
    void dfs(int[] arr, int index, int sum, int target) {
        if (index == arr.length) {
            if (sum == target) ans += 1;
            return;
        }
        dfs(arr, index + 1, sum - arr[index], target);
        dfs(arr, index + 1, sum + arr[index], target);
    }
}
