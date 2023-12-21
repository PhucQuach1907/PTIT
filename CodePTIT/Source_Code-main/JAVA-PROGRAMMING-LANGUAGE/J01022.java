import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);
    static long[] fib = new long[95];

    static String kthCharacter(long n, long k) {
        if (n == 1)
            return "0";
        if (n == 2)
            return "1";
        if (k <= fib[(int) n - 2])
            return kthCharacter(n - 2, k);
        return kthCharacter(n - 1, k - fib[(int) n - 2]);
    }

    static void Solve() {
        long n = sc.nextLong(), k = sc.nextLong();
        System.out.println(kthCharacter(n, k));
    }

    public static void main(String[] args) throws Exception {
        fib[1] = fib[2] = 1;
        for (long i = 3; i < 93; i++)
            fib[(int) i] = fib[(int) i - 1] + fib[(int) i - 2];
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
