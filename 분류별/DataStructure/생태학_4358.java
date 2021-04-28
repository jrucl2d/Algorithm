import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        Map<String, Integer> map = new HashMap<>();
        int count = 0;
        List<String> list = new ArrayList<>();
        while (sc.hasNext()) {
            try {
                String now = sc.nextLine();
                count += 1;
                if (map.containsKey(now)) {
                    map.put(now, map.get(now) + 1);
                    continue;
                }
                map.put(now, 1);
                list.add(now);
            }
            catch (Exception e) {
                break;
            }
        }
        list.sort((a, b) -> a.compareTo(b));
        for (String now : list) {
            double str_cnt = (double)map.get(now) / count;
            double val = Math.round((str_cnt *1000000)) / (double)10000;
            System.out.println(now + " " + String.format("%.4f", val));
        }
    }
}
