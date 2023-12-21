import java.util.*;

public class App {
    static int n, k, a[] = new int[1001], b[] = new int[1001];

    public static void inp(Scanner scanner) {
        n = scanner.nextInt();
        k = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            b[i] = scanner.nextInt();
        }
        Arrays.sort(b, 0, n + 1);
    }

    public static void inkq() {
        for (int i = 1; i <= k; i++) {
            System.out.print(b[a[i]] + " ");
        }
        System.out.println();
    }

    public static void ql(int i) {
        for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
            a[i] = j;
            if (i == k) {
                inkq();
            } else
                ql(i + 1);
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            inp(scanner);
            ql(1);
        }
    }
}
