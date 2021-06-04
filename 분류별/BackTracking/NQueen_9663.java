import java.io.*;
import java.util.*;

public class Main {
	static int n, ans = 0;
	static int[] arr = new int[16]; // i행 arr[i]열에 퀸이 놓임

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		sol(0);
		System.out.println(ans);
	}
	static void sol(int index) {
		if (index == n) {
			ans += 1;
			return;
		}
		for (int i = 0; i < n; i++) {
			arr[index] = i; // index행 i열에 퀸 추가
			if (possible(index)) {
				sol(index + 1);
			}
		}
	}
	static boolean possible(int index) {
		for (int i = 0; i < index; i++) {
			// 열이 같은 경우, 대각선(차이가 같음)인 경우
			if (arr[i] == arr[index] || (index - i == Math.abs(arr[index] - arr[i]))) {
				return false;
			}
		}
		return true;
	}
}
