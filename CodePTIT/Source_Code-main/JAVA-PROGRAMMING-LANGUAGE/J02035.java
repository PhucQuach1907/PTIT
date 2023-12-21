import java.util.*;
import java.io.*;;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextLong();
        long mn = a[0];
        for (int i = 1; i < n; i++)
            mn = Math.min(mn, a[i]);
        for (int i = 0; i < n; i++) {
            if (a[i] == mn) {
                System.out.println(i);
                return;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}