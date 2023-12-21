import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static long qpow(long a, long b) {
        long MOD = (long) 1e9 + 7;
        long res = 1;
        while (b > 0) {
            if (b % 2 == 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    public static void main(String[] args) throws Exception {
        while (true) {
            long a = sc.nextLong(), b = sc.nextLong();
            if (a == 0 && b == 0)
                break;
            System.out.println(qpow(a, b));
        }
    }
}
