import java.io.*;
import java.util.*;

public class Main {
    static int l, c;
    static char[] arr;
    static int[] visiting;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        l = Integer.valueOf(st.nextToken());
        c = Integer.valueOf(st.nextToken());
        arr = new char[c];
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        for (int i = 0; i < c; i++) {
            arr[i] = st.nextToken().charAt(0);
        }
        Arrays.sort(arr);
        visited = new boolean[c];
        visiting = new int[l];
        dfs(0, 0, 0, 0);
    }

    static void dfs(int index, int start, int ja, int mo) {
        if (index == l) {
            if (ja < 2 || mo < 1)
                return;
            for (int i : visiting) {
                System.out.print(arr[i]);
            }
            System.out.println();
            return;
        }
        for (int i = start; i < c; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            visiting[index] = i;
            boolean ismo = isMo(arr[i]);
            int nja = ismo ? ja : ja + 1;
            int nmo = ismo ? mo + 1 : mo;
            dfs(index + 1, i + 1, nja, nmo);
            visited[i] = false;
        }
    }

    static boolean isMo(char a) {
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
            return true;
        return false;
    }
}