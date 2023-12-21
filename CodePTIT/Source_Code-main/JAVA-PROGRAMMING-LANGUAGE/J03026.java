import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String a = sc.next(), b = sc.next();
        System.out.println(a.equals(b) ? -1 : Math.max(a.length(), b.length()));
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0) {
            Solve();
        }

    }
}
