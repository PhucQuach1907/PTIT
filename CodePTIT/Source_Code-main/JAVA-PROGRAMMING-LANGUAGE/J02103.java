import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve(int tc) {
        int n = sc.nextInt(), m = sc.nextInt();
        int[][] a = new int[n + 5][m + 5];
        int[][] b = new int[m + 5][n + 5];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = sc.nextInt();
                b[j][i] = a[i][j];
            }
        }
        System.out.printf("Test %d:\n", tc);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int res = 0;
                for (int k = 1; k <= m; k++)
                    res += a[i][k] * b[k][j];
                System.out.printf("%d ", res);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++)
            Solve(i);
    }
}
