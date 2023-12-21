import java.util.*;
import java.io.*;;

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int n = sc.nextInt(), k = sc.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextLong();
        Arrays.sort(a);
        for (int i = 0; i < n; i++) {
            if (a[i] >= 0)
                break;
            if (k > 0) {
                a[i] = -a[i];
                k--;
            }
        }
        Arrays.sort(a);
        if (k > 0) {
            a[0] = (k % 2 == 0 ? a[0] : -a[0]);
        }
        long res = 0;
        for (int i = 0; i < n; i++)
            res += a[i];
        System.out.println(res);
    }
}