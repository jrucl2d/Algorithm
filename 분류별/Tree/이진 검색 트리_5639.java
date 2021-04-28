import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node root = new Node(n);
        while(sc.hasNext()) {
            try {
                n = sc.nextInt();
                makeTree(n, root);
            } catch (Exception e) {
                break;
            }
        }
        Post(root);
    }
    static void Post(Node now) {
        if (now.l != null) Post(now.l);
        if (now.r != null) Post(now.r);
        System.out.println(now.val);
    }
    static void makeTree(int val, Node now) {
        if (now.l == null && now.val > val) {
            now.l = new Node(val);
            return;
        }
        if (now.r == null && now.val < val) {
            now.r = new Node(val);
            return;
        }
        if (now.val > val) {
            makeTree(val, now.l);
            return;
        }
        if (now.val < val) {
            makeTree(val, now.r);
        }
    }
    static class Node {
        int val;
        Node l, r;
        Node(int val) {this.val=val;}
    }
}
