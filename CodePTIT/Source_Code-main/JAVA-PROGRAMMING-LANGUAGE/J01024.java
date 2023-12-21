import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0 && digit != 1 && digit != 2) {
                System.out.println("NO");
                return;
            }
            n /= 10;
        }
        System.out.println("YES");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
