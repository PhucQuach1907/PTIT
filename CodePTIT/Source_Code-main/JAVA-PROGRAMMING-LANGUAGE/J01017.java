import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        long n = sc.nextLong();
        long prev = n % 10;
        n /= 10;
        while (n > 0) {
            long cur = n % 10;
            if (Math.abs(cur - prev) != 1) {
                System.out.println("NO");
                return;
            }
            prev = cur;
            n /= 10;
        }
        System.out.println("YES");

    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
