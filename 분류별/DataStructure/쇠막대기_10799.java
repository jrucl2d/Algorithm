import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String line = br.readLine();
		int ans = 0, stack = 0;
		for (int i = 0; i < line.length(); i++) {
			if (line.charAt(i) == '(') {
				if (i + 1 < line.length() && line.charAt(i + 1) == ')') {
					i += 1;
					ans += stack;
				} else {
					stack += 1;
				}
			} else {
				stack -= 1;
				ans += 1;
			}
		}
		bw.write(String.valueOf(ans));
		bw.flush();
	}
}
