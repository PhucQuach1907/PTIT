import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String str = sc.next();
        Stack<Integer> stk = new Stack<>();
        int res = 0;
        stk.add(-1);
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(')
                stk.add(i);
            else {
                stk.pop();
                if (!stk.empty())
                    res = Math.max(res, i - stk.peek());
                if (stk.empty())
                    stk.add(i);
            }
        }
        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
