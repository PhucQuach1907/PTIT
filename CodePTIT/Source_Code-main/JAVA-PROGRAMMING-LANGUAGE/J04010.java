import java.util.*;
import static java.lang.Math.*;

class Point {
    public double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distance(Point other) {
        return sqrt(pow(this.x - other.x, 2) + pow(this.y - other.y, 2));
    }
}

class Triangle {
    private Point p1, p2, p3;

    public Triangle(Point p1, Point p2, Point p3) {
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    public boolean isTriangle() {
        double tmp = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
        return tmp != 0;
    }

    public double getPerimeter() {
        return p1.distance(p2) + p1.distance(p3) + p2.distance(p3);
    }

    public double getAreaOfCircumcircle() {
        double a = p1.distance(p2), b = p1.distance(p3), c = p2.distance(p3);
        double halfPerimeter = this.getPerimeter() / 2;
        double area = sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
        double r = (a * b * c) / (4 * area);
        return Math.PI * r * r;
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        double a = sc.nextDouble(), b = sc.nextDouble(), c = sc.nextDouble(), d = sc.nextDouble(), e = sc.nextDouble(),
                f = sc.nextDouble();
        Point p1 = new Point(a, b);
        Point p2 = new Point(c, d);
        Point p3 = new Point(e, f);
        Triangle tri = new Triangle(p1, p2, p3);
        if (!tri.isTriangle())
            System.out.println("INVALID");
        else
            System.out.printf("%.3f\n", tri.getAreaOfCircumcircle());
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}