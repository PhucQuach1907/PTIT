import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String a = sc.next(), b = sc.next();
        BigInteger num1 = new BigInteger(a);
        BigInteger num2 = new BigInteger(b);
        System.out.println(num1.add(num2));
    }
}