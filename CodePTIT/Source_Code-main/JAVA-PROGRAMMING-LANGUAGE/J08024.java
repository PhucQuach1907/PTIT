import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        BigInteger n = new BigInteger(sc.next());
        Queue<String> q = new LinkedList<>();
        q.add("9");
        while (!q.isEmpty()) {
            String cur = q.peek();
            q.remove();
            BigInteger tmp = new BigInteger(cur);
            if (tmp.mod(n).equals(new BigInteger("0"))) {
                System.out.println(cur);
                return;
            }
            q.add(cur + "0");
            q.add(cur + "9");
        }
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
