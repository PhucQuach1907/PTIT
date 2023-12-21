import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);
    static long res[] = new long[50];

    static long gcd(long a, long b) {
        return (b == 0 ? a : gcd(b, a % b));
    }

    static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public static void main(String[] args) throws Exception {
        res[1] = 1;
        for (long i = 2; i < 50; i++)
            res[(int) i] = lcm(res[(int) i - 1], i);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            System.out.println(res[n]);
        }
    }
}
