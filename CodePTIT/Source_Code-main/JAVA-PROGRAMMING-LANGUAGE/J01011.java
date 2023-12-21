import java.util.*;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static long gcd(long a, long b) {
        return (b == 0l ? a : gcd(b, a % b));
    }

    static void Solve() {
        long a = sc.nextLong(), b = sc.nextLong();
        long GCD = gcd(a, b);
        System.out.printf("%d %d\n", (a * b) / GCD, GCD);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
