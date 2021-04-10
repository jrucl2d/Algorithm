
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
import java.util.*;
class Solution {
    public int solution(String[] words) {
            int n = words.length;
            int answer = 0;
            Arrays.sort(words);
            for (int i = 0; i < n; i++) {
                int sameCount = 0;
                if (i != 0) {
                    sameCount = getSameCount(words[i - 1], words[i]);
                }
                if (i != n - 1) {
                    sameCount = Math.max(sameCount, getSameCount(words[i], words[i + 1]));
                }
                if (sameCount == words[i].length()) answer += sameCount;
                else answer += sameCount + 1;
            }

            return answer;
        }

        private int getSameCount(String a, String b) {
            int ret = 0;
            int aLen = a.length(), bLen = b.length();
            int smallLen = aLen < bLen ? aLen : bLen;
            for (int i = 0; i < smallLen; i++) {
                if (a.charAt(i) != b.charAt(i)) break;
                ret += 1;
            }
            return ret;
        }
}