import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.valueOf(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            String s = br.readLine();
            sb.append(getAns(s) + "\n");
        }
        System.out.println(sb);
    }

    static String getAns(String s) {
        Stack<Character> front = new Stack<>(), back = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char now = s.charAt(i);
            if (now == '<') {
                if (front.isEmpty())
                    continue;
                back.add(front.pop());
                continue;
            }
            if (now == '>') {
                if (back.isEmpty())
                    continue;
                front.add(back.pop());
                continue;
            }
            if (now == '-') {
                if (front.isEmpty())
                    continue;
                front.pop();
                continue;
            }
            front.add(now);
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < front.size(); i++) {
            ans.append(front.get(i));
        }
        while (!back.isEmpty()) {
            ans.append(back.pop());
        }
        return ans.toString();
    }
}