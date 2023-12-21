import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        int a[] = new int[n], pref[] = new int[n], sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            sum += a[i];
        }
        pref[0] = a[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + a[i];
        int res = -1;
        for (int i = 1; i < n - 1; i++) {
            if (pref[i] - a[i] == sum - pref[i]) {
                res = i + 1;
                break;
            }
        }
        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}