import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        ArrayList<Integer> ans = new ArrayList<>(Collections.nCopies(n, -1));
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && a[i] > a[stk.peek()]) {
                ans.set(stk.peek(), a[i]);
                stk.pop();
            }
            stk.add(i);
        }
        for (Integer x : ans)
            System.out.printf("%d ", x);
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
