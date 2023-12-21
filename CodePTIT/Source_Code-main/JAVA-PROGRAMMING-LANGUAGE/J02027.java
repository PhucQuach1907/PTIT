import java.util.*;
import java.io.*;;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static long lower_bound(long a[], long key) {
        long index = (long) Arrays.binarySearch(a, key);
        if (index < 0) {
            return -1l * index - 1;
        } else {
            while (index > 0) {
                if (a[(int) index - 1] == key)
                    index--;
                else
                    return index;
            }
            return index;
        }
    }

    static void Solve() {
        int n = sc.nextInt();
        long k = sc.nextLong();
        long a[] = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        Arrays.sort(a);
        long res = 0;
        for (int i = 0; i < n; i++) {
            long val = a[i] + k;
            long idx = lower_bound(a, val);
            res += (long) (idx - i - 1);
        }
        System.out.println(res);
    }

    public static void main(String[] args) throws IOException {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
