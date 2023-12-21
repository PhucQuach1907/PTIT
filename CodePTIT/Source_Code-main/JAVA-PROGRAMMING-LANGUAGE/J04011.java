import java.util.*;

class Point3D {
    private int x, y, z;

    public Point3D(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    static boolean check(Point3D p1, Point3D p2, Point3D p3, Point3D p4) {
        int a1 = p2.x - p1.x;
        int b1 = p2.y - p1.y;
        int c1 = p2.z - p1.z;
        int a2 = p3.x - p1.x;
        int b2 = p3.y - p1.y;
        int c2 = p3.z - p1.z;
        int a = b1 * c2 - b2 * c1;
        int b = a2 * c1 - a1 * c2;
        int c = a1 * b2 - b1 * a2;
        int d = (-a * p1.x - b * p1.y - c * p1.z);
        return a * p4.x + b * p4.y + c * p4.z + d == 0;
    }
}

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Point3D p1 = new Point3D(sc.nextInt(), sc.nextInt(), sc.nextInt());
            Point3D p2 = new Point3D(sc.nextInt(), sc.nextInt(), sc.nextInt());
            Point3D p3 = new Point3D(sc.nextInt(), sc.nextInt(), sc.nextInt());
            Point3D p4 = new Point3D(sc.nextInt(), sc.nextInt(), sc.nextInt());
            if (Point3D.check(p1, p2, p3, p4)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}