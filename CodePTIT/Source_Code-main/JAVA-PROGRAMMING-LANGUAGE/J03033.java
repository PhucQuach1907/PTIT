import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String a = sc.next(), b = sc.next();
        BigInteger num1 = new BigInteger(a), num2 = new BigInteger(b);
        System.out.println(num1.multiply(num2).divide(num1.gcd(num2)));
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            Solve();
        }
    }
}
