import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        int a[] = new int[n], res[] = new int[n];
        Arrays.fill(res, -1);
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        Stack<Integer> stk = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && a[i] > a[stk.peek()]) {
                res[stk.peek()] = i;
                stk.pop();
            }
            stk.add(i);
        }
        for (int i = 0; i < n; i++)
            System.out.printf("%d ", i - res[i]);
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
