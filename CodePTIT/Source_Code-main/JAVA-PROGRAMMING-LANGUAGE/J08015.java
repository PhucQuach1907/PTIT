import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt(), k = sc.nextInt();
        int a[] = new int[n];
        HashMap<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (!cnt.containsKey(a[i]))
                cnt.put(a[i], 1);
            else
                cnt.put(a[i], cnt.get(a[i]) + 1);
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            int tmp = k - a[i];
            if (cnt.containsKey(tmp)) {
                res += cnt.get(tmp);
                if (tmp == a[i])
                    res--;
            }
        }
        System.out.println(res / 2);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
