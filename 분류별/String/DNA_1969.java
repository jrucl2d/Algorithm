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
        int n, m;
        int[][] dist;

        public void solution() throws IOException {
            input();
        }

        void input() throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            dist = new int[m][4]; // A, C, G, T
            for (int i = 0; i < n; i++) {
                String now = br.readLine();
                for (int j = 0; j < m; j++) {
                    switch (now.charAt(j)) {
                        case 'A':
                            dist[j][0] += 1;
                            break;
                        case 'C':
                            dist[j][1] += 1;
                            break;
                        case 'G':
                            dist[j][2] += 1;
                            break;
                        case 'T':
                            dist[j][3] += 1;
                            break;
                    }
                }
            }
            StringBuilder ans = new StringBuilder();
            int ansCnt = 0;
            for (int i = 0; i < m; i++) {
                int innerCnt = -1;
                int index = 0;
                for (int j = 3; j >= 0; j--) {
                    if (innerCnt <= dist[i][j]) {
                        innerCnt = dist[i][j];
                        index = j;
                    }
                }
                switch (index) {
                    case 0:
                        ans.append('A');
                        break;
                    case 1:
                        ans.append('C');
                        break;
                    case 2:
                        ans.append('G');
                        break;
                    case 3:
                        ans.append('T');
                        break;
                }
                ansCnt += (n - innerCnt);
            }
            System.out.println(ans);
            System.out.println(ansCnt);
        }
    }
}

