import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        BigInteger a = new BigInteger(sc.next()), b = new BigInteger(sc.next());
        System.out.println(a.gcd(b));
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
