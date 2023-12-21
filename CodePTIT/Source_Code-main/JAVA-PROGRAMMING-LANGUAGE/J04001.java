import java.util.*;
import static java.lang.Math.*;

class Point {
    private double x;
    private double y;

    public Point() {

    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distance(Point p) {
        return sqrt(pow(this.x - p.x, 2) + pow(this.y - p.y, 2));
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        double a = sc.nextDouble(), b = sc.nextDouble(), c = sc.nextDouble(), d = sc.nextDouble();
        Point p = new Point(a, b);
        System.out.printf("%.4f\n", p.distance(new Point(c, d)));
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
