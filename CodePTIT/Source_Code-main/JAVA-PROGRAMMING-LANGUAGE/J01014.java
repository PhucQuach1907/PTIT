import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        long n = sc.nextLong();
        long res = 0;
        if (n % 2 == 0) {
            res = 2;
            while (n % 2 == 0)
                n /= 2;
        }
        for (long i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                res = i;
                while (n % i == 0)
                    n /= i;
            }
        }
        if (n > 2)
            res = Math.max(res, n);
        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
