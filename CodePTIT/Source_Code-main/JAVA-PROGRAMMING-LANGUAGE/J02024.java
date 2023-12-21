import java.util.*;

public class App {
    static int n, a[] = new int[1001], b[] = new int[1001], d[] = new int[1001];

    public static void inp(Scanner scanner) {
        n = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            d[i] = scanner.nextInt();
        }
        Arrays.sort(d, 0, n + 1);
        for (int i = 1; i <= n; i++) {
            b[i] = d[n - i + 1];
        }
    }

    public static void inkq() {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                sum += b[i];
            }
        }
        if (sum % 2 == 0)
            return;
        int cnt = 0, c[] = new int[1001];
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                System.out.print(b[i] + " ");
            }
        }
        System.out.println();
    }

    public static void ql(int i) {
        for (int j = 0; j <= 1; j++) {
            a[i] = j;
            if (i == n) {
                inkq();
            } else
                ql(i + 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            inp(scanner);
            ql(1);
        }
    }

}
