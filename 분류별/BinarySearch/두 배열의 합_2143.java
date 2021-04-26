import java.io.*;
import java.util.*;

public class Main {
    static int t, n, m;
    static int[] a, b;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.valueOf(br.readLine());
        n = Integer.valueOf(br.readLine());
        a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.valueOf(st.nextToken());
        }
        m = Integer.valueOf(br.readLine());
        b = new int[m];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < m; i++) {
            b[i] = Integer.valueOf(st.nextToken());
        }
        List<Long> alist = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int len = 0; len < (n - i); len++) {
                long tmp = 0;
                for (int j = i; j <= i + len; j++) {
                    tmp += a[j];
                }
                alist.add(tmp);
            }

        }
        List<Long> blist = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            for (int len = 0; len < (m - i); len++) {
                long tmp = 0;
                for (int j = i; j <= i + len; j++) {
                    tmp += b[j];
                }
                blist.add(tmp);
            }
        }
        alist.sort((a, b) -> Long.compare(a, b));
        blist.sort((a, b) -> Long.compare(a, b));
        long ans = 0;
        for (int i = 0; i < alist.size(); i++) {
            long find = t - alist.get(i);
            ans += (upperBound(blist, find) - lowerBound(blist, find));
        }
        System.out.println(ans);
    }
    static int lowerBound(List<Long> arr, long val) {
        int l = 0, r = arr.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if (val <= arr.get(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
    static int upperBound(List<Long> arr, long val) {
        int l = 0, r = arr.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if (val < arr.get(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
