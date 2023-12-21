import java.util.*;
import static java.lang.Math.*;

class Fraction {
    private long x;
    private long y;

    public Fraction(long x, long y) {
        this.x = x;
        this.y = y;
    }

    public long gcd(long a, long b) {
        return (b == 0 ? a : gcd(b, a % b));
    }

    @Override
    public String toString() {
        long GCD = gcd(x, y);
        return String.format("%d/%d", x / GCD, y / GCD);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        long a = sc.nextLong(), b = sc.nextLong();
        Fraction fr = new Fraction(a, b);
        System.out.println(fr);
    }
}
