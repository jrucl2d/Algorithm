import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static String line;
    static List<Info> infos;
    static List<String> ans = new ArrayList<>();
    static boolean[] visited;
    static int[] visiting;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        line = br.readLine();
        Stack<Info> stack = new Stack<>();
        infos = new ArrayList<>();
        for (int i = 0; i < line.length(); i++) {
            char now = line.charAt(i);
            if (now == '(') {
                stack.push(new Info(i, -1));
                continue;
            }
            if (now == ')') {
                Info top = stack.pop();
                infos.add(new Info(top.a, i));
            }
        }
        n = infos.size();
        visited = new boolean[n];
        for (int i = 1; i <= n; i++) {
            visiting = new int[i];
            dfs(0, 0);
        }
        ans.sort((aa, bb) -> aa.compareTo(bb));
        Set<String> dupCheck = new HashSet<>();
        for (String str : ans) {
            if (!dupCheck.add(str)) continue;
            System.out.println(str);
        }
    }
    static void dfs(int index, int start) {
        if (index == visiting.length) {
            StringBuilder sb = new StringBuilder();
            Set<Integer> remove = new HashSet<>();
            for (int i = 0; i < visiting.length; i++) {
                remove.add(infos.get(visiting[i]).a);
                remove.add(infos.get(visiting[i]).b);
            }
            for (int i = 0; i < line.length(); i++) {
                if (!remove.add(i)) continue;
                sb.append(line.charAt(i));
            }
            ans.add(sb.toString());
            return;
        }
        for (int i = start; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            visiting[index] = i;
            dfs(index + 1, i + 1);
            visited[i] = false;
        }
    }
    static class Info {
        int a, b;
        Info (int a, int b) {this.a=a;this.b=b;}
    }
}