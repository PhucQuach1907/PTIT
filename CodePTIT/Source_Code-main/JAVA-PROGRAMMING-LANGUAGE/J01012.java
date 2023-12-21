import java.util.*;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        if (n % 2 == 1)
            System.out.println(0);
        else {
            int res = 0;
            for (int i = 1; i <= Math.sqrt(n); i++) {
                if (n % i == 0) {
                    if (i % 2 == 0)
                        res++;
                    int other = n / i;
                    if (other != i && other % 2 == 0)
                        res++;
                }
            }
            System.out.println(res);
        }
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
