import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        long a[] = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextLong();
        Stack<Integer> stk = new Stack<>();
        long r[] = new long[n], l[] = new long[n];
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && a[i] < a[stk.peek()])
                r[stk.pop()] = i;
            stk.push(i);
        }
        while (!stk.empty())
            r[stk.pop()] = n;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && a[i] < a[stk.peek()])
                l[stk.pop()] = i;
            stk.push(i);
        }
        while (!stk.empty())
            l[stk.pop()] = -1;
        long res = 0;
        for (int i = 0; i < n; i++)
            res = Math.max(res, a[i] * (r[i] - l[i] - 1));
        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
