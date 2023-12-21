import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        if (n == 0) {
            System.out.println("Impossible");
            return;
        }
        HashSet<Integer> diffDigit = new HashSet<>();
        int mul = 1;
        while (true) {
            int tmp = n * mul;
            while (tmp > 0) {
                diffDigit.add(tmp % 10);
                tmp /= 10;
            }
            if (diffDigit.size() == 10) {
                System.out.println(n * mul);
                return;
            }
            mul++;
        }

    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}