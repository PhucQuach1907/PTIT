import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String a = sc.next();
        BigInteger num = new BigInteger(a);
        BigInteger tmp = new BigInteger("11");
        BigInteger targetMod = new BigInteger("0");
        System.out.println(num.mod(tmp).equals(targetMod) ? 1 : 0);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0)
            Solve();
    }
}