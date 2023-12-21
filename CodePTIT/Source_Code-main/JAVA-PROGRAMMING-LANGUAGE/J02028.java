import java.util.*;
import java.io.*;;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        long k = sc.nextLong();
        long a[] = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextLong();
        SortedSet<Long> mySet = new TreeSet<>();
        long sum = 0;
        mySet.add(sum);
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (mySet.contains(sum - k)) {
                System.out.println("YES");
                return;
            }
            mySet.add(sum);
        }
        System.out.println("NO");
    }

    public static void main(String[] args) throws IOException {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}