import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String a = sc.next(), b = sc.next();
        BigInteger num1 = new BigInteger(a), num2 = new BigInteger(b);
        BigInteger target = new BigInteger("0");
        System.out.println(num1.mod(num2).equals(target) || num2.mod(num1).equals(target) ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
