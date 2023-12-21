import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String a = sc.next(), b = sc.next();
        BigInteger num1 = new BigInteger(a);
        BigInteger num2 = new BigInteger(b);
        System.out.println(num1.add(num2));
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0)
            Solve();
    }
}