import java.util.*;

class Solution {
    public String[] solution(String[] files) {
            Arrays.sort(files, (a, b) -> {
                int[] number_index_a = {0};
                int[] number_index_b = {0};
                String aHead = getHead(a, number_index_a);
                String bHead = getHead(b, number_index_b);

                if (aHead.equalsIgnoreCase(bHead)) {
                    return getNumber(a, number_index_a[0]) - getNumber(b, number_index_b[0]);
                } else {
                    return aHead.toLowerCase().compareTo(bHead.toLowerCase());
                }
            });
            return files;
        }
        private int getNumber(String s, int start_index) {
            StringBuilder tmp = new StringBuilder();
            for (int i = start_index; i < s.length(); i++) {
                if (!Character.isDigit(s.charAt(i))) break;
                tmp.append(s.charAt(i));
            }
            return Integer.valueOf(tmp.toString());
        }
        private String getHead(String s, int[] number_index) {
            StringBuilder tmp = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                if (Character.isDigit(s.charAt(i))) {
                    number_index[0] = i;
                    break;
                }
                tmp.append(s.charAt(i));
            }
            return tmp.toString();
        }
}