import java.util.*;

class Point {
    public int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    static int Calc(Point A, Point B, Point C) {
        return Math.abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
    }

    static void Solve() {
        int n = sc.nextInt();
        Point[] arr = new Point[n];
        for (int i = 0; i < n; i++)
            arr[i] = new Point(sc.nextInt(), sc.nextInt());
        int tmp = 0;
        for (int i = 2; i < n; i++)
            tmp += Calc(arr[0], arr[i], arr[i - 1]);
        double res = (tmp * 1.0) / 2;
        System.out.printf("%.3f\n", res);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
