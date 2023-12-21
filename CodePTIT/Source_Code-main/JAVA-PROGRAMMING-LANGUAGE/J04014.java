import java.util.*;

class Fraction {
    private long x, y;

    public Fraction(long x, long y) {
        this.x = x;
        this.y = y;
    }

    static long GCD(long a, long b) {
        return (b == 0 ? a : GCD(b, a % b));
    }

    static long LCM(long a, long b) {
        return (a * b) / GCD(a, b);
    }

    public Fraction reduceFraction(long a, long b) {
        return new Fraction(a / GCD(a, b), b / GCD(a, b));
    }

    public Fraction add(Fraction other) {
        long resY = LCM(this.y, other.y);
        long resX = this.x * (resY / this.y) + other.x * (resY / other.y);
        return this.reduceFraction(resX, resY);
    }

    public Fraction mul(Fraction other) {
        long resX = this.x * other.x;
        long resY = this.y * other.y;
        return this.reduceFraction(resX, resY);
    }

    @Override
    public String toString() {
        return String.format("%d/%d", this.x, this.y);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        long a = sc.nextLong(), b = sc.nextLong(), c = sc.nextLong(), d = sc.nextLong();
        Fraction A = new Fraction(a, b);
        Fraction B = new Fraction(c, d);
        Fraction sum = A.add(B), product = A.mul(B);
        Fraction C = sum.mul(sum);
        Fraction D = product.mul(C);
        System.out.println(C + " " + D);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}