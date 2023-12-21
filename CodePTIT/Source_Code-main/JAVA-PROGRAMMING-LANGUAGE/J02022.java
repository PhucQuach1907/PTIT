import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);
    static int n;
    static int a[] = new int[15];
    static boolean isUsed[] = new boolean[15];

    static boolean Check() {
        for (int i = 2; i <= n; i++) {
            if (Math.abs(a[i] - a[i - 1]) == 1)
                return false;
        }
        return true;
    }

    static void Try(int k) {
        if (k > n)
            return;
        for (int i = 1; i <= n; i++) {
            if (!isUsed[i]) {
                a[k] = i;
                isUsed[i] = true;
                if (k == n) {
                    if (Check()) {
                        for (int j = 1; j <= n; j++)
                            System.out.printf("%d", a[j]);
                        System.out.println();
                    }
                } else
                    Try(k + 1);
                isUsed[i] = false;
            }
        }
    }

    static void Solve() {
        n = sc.nextInt();
        Arrays.fill(isUsed, false);
        Try(1);
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
