import java.lang.reflect.Array;
import java.util.*;

class Node {
    public int r, c, step;

    public Node(int r, int c, int step) {
        this.r = r;
        this.c = c;
        this.step = step;
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean canVisit(int r, int c, boolean vis[][]) {
        return (r > 0 && c > 0 && r < 9 && c < 9 && !vis[r][c]);
    }

    static void Solve() {
        int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
        int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
        String a = sc.next(), b = sc.next();
        int sr = a.charAt(1) - '0', sc = a.charAt(0) - 96, tr = b.charAt(1) - '0', tc = b.charAt(0) - 96;
        boolean[][] vis = new boolean[10][10];
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(sr, sc, 0));
        vis[sr][sc] = true;
        while (!q.isEmpty()) {
            Node cur = q.remove();
            if (cur.r == tr && cur.c == tc) {
                System.out.println(cur.step);
                return;
            }
            for (int i = 0; i < 8; i++) {
                if (canVisit(cur.r + dx[i], cur.c + dy[i], vis)) {
                    q.add(new Node(cur.r + dx[i], cur.c + dy[i], cur.step + 1));
                    vis[cur.r + dx[i]][cur.c + dy[i]] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
