import java.util.*;

class Point {
    public double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    static Point nextPoint(Scanner sc) {
        return new Point(sc.nextDouble(), sc.nextDouble());
    }

    public double distance(Point other) {
        return Math.sqrt(Math.pow(this.x - other.x, 2) + Math.pow(this.y - other.y, 2));
    }
}

class Triangle {
    private Point p1, p2, p3;

    public Triangle(Point p1, Point p2, Point p3) {
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    public boolean valid() {
        double tmp = p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
        return tmp != 0;
    }

    public String getPerimeter() {
        return String.format("%.3f", p1.distance(p2) + p1.distance(p3) + p2.distance(p3));
    }
}

public class App {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Triangle a = new Triangle(Point.nextPoint(sc), Point.nextPoint(sc), Point.nextPoint(sc));
            if (!a.valid()) {
                System.out.println("INVALID");
            } else {
                System.out.println(a.getPerimeter());
            }
        }
    }
}