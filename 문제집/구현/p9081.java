import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class p9081 {
    static int n;

    public static void main(String[] args) throws IOException {
        input();
    }
    static void sol(String line) {
        int arr[] = new int[line.length()];
        for (int i = 0; i < line.length(); i++) {
            arr[i] = (int)line.charAt(i);
        }
        List<Integer> tmp = new ArrayList<>();
        int stopped_index = 0;
        for (int i = arr.length - 1; i > 0; i--) {
            if (arr[i] <= arr[i - 1]) {
                tmp.add(arr[i]);
                if (i - 1 == 0) {
                    System.out.println(line);
                    return;
                }
            } else {
                tmp.add(arr[i]);
                stopped_index = i - 1;
                break;
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < stopped_index; i++) {
            sb.append(line.charAt(i));
        }
        int lower_limit = arr[stopped_index];
        int the_min = Integer.MAX_VALUE;
        int the_index = 0;
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp.get(i) > lower_limit) {
                if (the_min > tmp.get(i)) {
                    the_min = tmp.get(i);
                    the_index = i;
                }
            }
        }
        sb.append((char) the_min);
        tmp.remove(the_index);
        tmp.add(lower_limit);
        tmp.sort((a, b) -> a - b);
        for (int i = 0; i < tmp.size(); i++) {
            sb.append((char) (int)tmp.get(i));
        }
        System.out.println(sb);
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            sol(line);
        }
    }
}
