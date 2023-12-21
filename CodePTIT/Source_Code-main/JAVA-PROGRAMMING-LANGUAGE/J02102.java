import java.util.*;
import java.io.*;;

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int n = sc.nextInt();
        int v[] = new int[n * n];
        for (int i = 0; i < n * n; i++)
            v[i] = sc.nextInt();
        Arrays.sort(v);
        int a[][] = new int[n][n];
        int index = 0, size = n - 1, h = n * n, d = 0, l1 = 0;
        while (d <= n / 2) {
            for (int i = d; i <= size; i++)
                a[d][i] = v[index++];
            if (index == h)
                break;
            for (int i = d + 1; i <= size; i++)
                a[i][size] = v[index++];
            if (index == h)
                break;
            for (int i = size - 1; i >= d; i--)
                a[size][i] = v[index++];
            if (index == h)
                break;
            for (int i = size - 1; i > d; i--)
                a[i][d] = v[index++];
            if (index == h)
                break;
            d++;
            size--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                System.out.printf("%d ", a[i][j]);
            System.out.println();
        }
    }
}