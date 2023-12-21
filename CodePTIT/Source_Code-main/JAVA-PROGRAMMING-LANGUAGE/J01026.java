import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        int tmp = (int) Math.sqrt(n);
        System.out.println(tmp * tmp == n ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
