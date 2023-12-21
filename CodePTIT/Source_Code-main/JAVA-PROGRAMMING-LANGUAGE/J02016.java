import java.util.*;
import java.io.*;;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextLong();
        Arrays.sort(a);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long tmp = (long) Math.sqrt(a[i] * a[i] + a[j] * a[j]);
                if (tmp * tmp == a[i] * a[i] + a[j] * a[j]) {
                    if (Arrays.binarySearch(a, tmp) >= 0) {
                        System.out.println("YES");
                        return;
                    }
                }
            }
        }
        System.out.println("NO");
    }

    public static void main(String[] args) throws IOException {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}