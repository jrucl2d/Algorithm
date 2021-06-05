import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		List<Integer> origin = new ArrayList<>();
		List<Integer> arr = new ArrayList<>();
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
			origin.add(arr.get(i));
		}
		Collections.sort(arr);
		List<Integer> narr = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			if (!arr.get(i).equals(arr.get(i + 1))) narr.add(arr.get(i));
		}
		narr.add(arr.get(n - 1));
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(lowerBound(narr, 0, narr.size(), origin.get(i)) + " ");
		}
		System.out.println(sb);
	}
	static int lowerBound(List<Integer> list, int l, int r, int v) {
		if (l < r) {
			int m = (l + r) / 2;
			if (list.get(m) >= v) {
				return lowerBound(list, l, m, v);
			}
			return lowerBound(list, m + 1, r, v);
		}
		return r;
	}
}
