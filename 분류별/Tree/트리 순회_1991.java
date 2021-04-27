import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static Node[] arr = new Node[27];
    static StringBuilder pre = new StringBuilder();
    static StringBuilder in = new StringBuilder();
    static StringBuilder post = new StringBuilder();


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        char a, b, c;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            a = st.nextToken().charAt(0);
            b = st.nextToken().charAt(0);
            c = st.nextToken().charAt(0);
            Node newNode = new Node(-1, -1);
            if (b != '.') newNode.left = b - 'A';
            if (c != '.') newNode.right = c - 'A';
            arr[a - 'A'] = newNode;
        }
        Pre(0);
        In(0);
        Post(0);
        System.out.println(pre);
        System.out.println(in);
        System.out.println(post);
    }
    static void Pre(int now) {
        pre.append((char)(now + 'A'));
        if (arr[now].left != -1) Pre(arr[now].left);
        if (arr[now].right != -1) Pre(arr[now].right);
    }
    static void In(int now) {
        if (arr[now].left != -1) In(arr[now].left);
        in.append((char)(now + 'A'));
        if (arr[now].right != -1) In(arr[now].right);
    }
    static void Post(int now) {
        if (arr[now].left != -1) Post(arr[now].left);
        if (arr[now].right != -1) Post(arr[now].right);
        post.append((char)(now + 'A'));
    }
    static class Node {
        int left, right;
        Node (int left, int right) {this.left=left;this.right=right;}
    }
}
