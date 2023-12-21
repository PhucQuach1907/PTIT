import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        BigInteger a = new BigInteger(sc.next()), b = new BigInteger(sc.next());
        BigInteger res = a.subtract(b);
        System.out.println(res);
    }
}
