import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Solution solution = new Solution();
        solution.solution();
    }
    static class Solution {
        String s;

        public void solution() throws IOException {
            input();
            System.out.println(logic());
        }

        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            s = br.readLine();
        }
        int logic() {
            // 전체가 같으면 -1
            boolean same = true;
            char first = s.charAt(0);
            for (int i = 0; i < s.length(); i++) {
                if (first != s.charAt(i)) {
                    same = false;
                    break;
                }
            }
            if (same) return -1;
            int ans;
            // 전체가 팰린드롬이면 전체길이 - 1
            if (isPalin(0, s.length() - 1)) {
                ans = s.length() - 1;
            }
            // 전체가 팰린드롬이 아니면 전체길이
            else {
                ans = s.length();
            }
            return ans;
        }
        boolean isPalin(int i, int j) {
            if (i == j) return true;
            else if (i + 1 == j) {
                if (s.charAt(i) == s.charAt(j)) return true;
                else return false;
            }
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
            return isPalin(i + 1, j - 1);
        }
    }
}

