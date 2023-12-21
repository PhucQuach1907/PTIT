import java.util.*;
import java.io.*;

class Point {
    public int x, y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Polygon {
    public Point p[];

    public Polygon(Point p[]) {
        this.p = p;
    }

    public int Calc(Point A, Point B, Point C) {
        return Math.abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
    }

    public String getArea() {
        int tmp = 0;
        for (int i = 2; i < p.length; i++)
            tmp += Calc(p[0], p[i], p[i - 1]);
        double res = (tmp * 1.0) / 2;
        return String.format("%.3f", res);
    }
}

public class App {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("POLYGON.in"));
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            Point p[] = new Point[n];
            for (int i = 0; i < n; i++) {
                p[i] = new Point(in.nextInt(), in.nextInt());
            }
            Polygon poly = new Polygon(p);
            System.out.println(poly.getArea());
        }
    }

}
