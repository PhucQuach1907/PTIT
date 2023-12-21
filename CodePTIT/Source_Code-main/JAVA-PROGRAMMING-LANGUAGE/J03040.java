import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean Check(String str) {
        char a = str.charAt(5), b = str.charAt(6), c = str.charAt(7), d = str.charAt(9), e = str.charAt(10);
        if (a < b && b < c && c < d && d < e)
            return true;
        if (a == b && b == c && c == d && d == e)
            return true;
        if (a == b && b == c && d == e)
            return true;
        if ((a == '6' || a == '8') && (b == '6' || b == '8') && (c == '6' || c == '8') && (d == '6' || d == '8')
                && (e == '6' || e == '8'))
            return true;
        return false;

    }

    static void Solve() {
        String lp = sc.next();
        System.out.println(Check(lp) ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
