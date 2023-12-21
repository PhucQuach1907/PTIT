import java.util.*;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static void Solve(int tc) {
        int n = sc.nextInt();
        System.out.printf("Test %d: ", tc);
        int cnt = 0;
        if (n % 2 == 0) {
            while (n % 2 == 0) {
                n /= 2;
                cnt++;
            }
            System.out.printf("2(%d) ", cnt);
        }
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                System.out.printf("%d(%d) ", i, cnt);
            }
        }
        if (n > 2)
            System.out.printf("%d(1)", n);
        System.out.printf("\n");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++)
            Solve(i);
    }
}
