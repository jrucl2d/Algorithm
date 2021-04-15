import java.util.*;
class Solution {
    int n, root_num, root_height = -1;
    Info[] info;
    Node[] tree;
    int[] pre, post;
    int pre_index = 0, post_index = 0;
    public int[][] solution(int[][] nodeinfo) {
        n = nodeinfo.length;
        info = new Info[n];
        tree = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = new Node(i);
        }
        for (int i = 0; i < n; i++) {
            info[i] = new Info(nodeinfo[i][0], nodeinfo[i][1], i + 1);
        }
        Arrays.sort(info, (a, b) -> {
            if (a.x == b.x) {
                return a.y - b.y;
            }
            return a.x - b.x;
        });
        for (int i = 0; i < n; i++) {
            Info now = info[i];
            if (root_height < now.y) {
                root_height = now.y;
                root_num = now.num;
            }
            int child = -1, child_height = -1;
            for (int j = i + 1; j < n; j++) {
                if (info[j].y < now.y && child_height < info[j].y) {
                    child_height = info[j].y;
                    child = info[j].num;
                }
                if (info[j].y > now.y) {
                    if (tree[info[j].num].left == 0)
                        tree[info[j].num].left = now.num;
                    if (tree[now.num].parent == 0)
                        tree[now.num].parent = info[j].num;
                    break;
                }
            }
            if (child != -1) {
                if(tree[child].parent == 0)
                    tree[child].parent = now.num;
                if (tree[now.num].right == 0)
                    tree[now.num].right = child;
            }
        }
        pre = new int[n];
        post = new int[n];
        getPre(root_num);
        getPost(root_num);
        int[][] ans = new int[2][n];
        ans[0] = pre;
        ans[1] = post;
        return ans;
    }
    void getPre(int node) {
        pre[pre_index++] = node;
        if (tree[node].left != 0) getPre(tree[node].left);
        if (tree[node].right != 0) getPre(tree[node].right);
    }
    void getPost(int node) {
        if (tree[node].left != 0) getPost(tree[node].left);
        if (tree[node].right != 0) getPost(tree[node].right);
        post[post_index++] = node;
    }
    class Info {
        int x, y, num;
        Info(int x, int y, int num) {this.x=x;this.y=y;this.num=num;}
    }
    class Node {
        int num, left, right, parent;
        Node(int num) {this.num=num;left=0;right=0;parent=0;}
    }
}