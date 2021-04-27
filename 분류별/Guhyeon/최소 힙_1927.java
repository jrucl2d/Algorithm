import java.io.*;
import java.util.*;

public class Main {
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int now = Integer.valueOf(br.readLine());
            if (now == 0) {
                sb.append(MaxHeap.pop() + "\n");
                continue;
            }
            MaxHeap.insert(now);
        }
        System.out.println(sb);
    }
    static class MaxHeap {
        private static final int SIZE = 100001;
        private static int[] heap = new int[SIZE];
        private static int top = 0;

        static boolean isEmpty() {
            if (top == 0) return true;
            return false;
        }
        static int pop() {
            if (isEmpty()) return 0;
            int tmp = heap[1];
            swap(1, top);
            top -= 1;
            int p = 1;
            int c = p * 2;
            while (true) {
                if (c + 1 <= top && heap[c] > heap[c + 1]) c += 1;
                if (c <= top && heap[p] > heap[c]) {
                    swap(p, c);
                    p = c;
                    c *= 2;
                    continue;
                }
                break;
            }
            return tmp;
        }
        static void insert(int val) {
            heap[++top] = val;
            int p = (top) / 2;
            int c = top;
            while (true) {
                if (p >= 1 && c >= 1 && heap[p] > heap[c]) {
                    swap(p, c);
                    c = p;
                    p = p / 2;
                    continue;
                } else break;
            }
        }

        static private void swap(int a, int b) {
            int tmp = heap[a];
            heap[a] = heap[b];
            heap[b] = tmp;
        }
    }
}
