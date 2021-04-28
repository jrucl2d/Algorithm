import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int tc = 1;
        StringBuilder sb = new StringBuilder();
        while (true) {
            Set set = new HashSet();
            Map<Integer, Integer> ind = new HashMap<>();
            boolean done = false;
            int ind_count = 0;
            while (true) {
                int a = sc.nextInt();
                int b = sc.nextInt();

                if (a == 0 && b == 0) break;
                if (a == -1 && b == -1) {
                    done = true;
                    break;
                }

                set.add(a); set.add(b);
                ind_count += 1;
                if (!ind.containsKey(a)) ind.put(a, 0);
                if (!ind.containsKey(b)) { ind.put(b, 1); continue; }
                ind.put(b, ind.get(b) + 1);
            }
            if (done) break;
            if (set.size() == 0) { sb.append(makeAns(tc++, true)); continue; }
            if (ind_count + 1 != set.size()) { sb.append(makeAns(tc++, false)); continue; }
            Iterator it = set.iterator();
            int root_count = 0;
            boolean nope = false;
            while(it.hasNext()) {
                int now = (int)it.next();
                if (ind.get(now) == 0) root_count += 1;
                if (ind.get(now) > 1) {
                    nope = true;
                    break;
                }
            }
            if (nope || root_count != 1) {
                sb.append(makeAns(tc++, false)); continue;
            }
            sb.append(makeAns(tc++, true));
        }
        System.out.println(sb);
    }
    static String makeAns(int k, boolean is) {
        if (is) return "Case " + k + " is a tree.\n";
        return "Case " + k + " is not a tree.\n";
    }
}
