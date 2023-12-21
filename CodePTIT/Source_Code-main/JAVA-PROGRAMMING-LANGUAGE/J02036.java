import java.util.*;
import java.io.*;;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static int GCD(int a, int b) {
        return (b == 0 ? a : GCD(b, a % b));
    }

    static int LCM(int a, int b) {
        return (a * b) / GCD(a, b);
    }

    static void Solve() {
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(a[0]);
        for (int i = 1; i < n; i++)
            arr.add(LCM(a[i], a[i - 1]));
        arr.add(a[a.length - 1]);
        for (Integer x : arr)
            System.out.printf("%d ", x);
        System.out.println();
    }

    public static void main(String[] args) throws IOException {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}