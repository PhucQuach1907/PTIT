import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);
    static int n, k, cnt = 0;
    static int a[] = new int[15];

    static void Try(int curIndex) {
        if (curIndex > k)
            return;
        for (int i = a[curIndex - 1] + 1; i <= n - k + curIndex; i++) {
            a[curIndex] = i;
            if (curIndex == k) {
                cnt++;
                for (int j = 1; j <= k; j++)
                    System.out.printf("%d ", a[j]);
                System.out.println();
            } else
                Try(curIndex + 1);
        }
    }

    public static void main(String[] args) throws Exception {
        n = sc.nextInt();
        k = sc.nextInt();
        a[0] = 0;
        Try(1);
        System.out.printf("Tong cong co %d to hop", cnt);
    }
}