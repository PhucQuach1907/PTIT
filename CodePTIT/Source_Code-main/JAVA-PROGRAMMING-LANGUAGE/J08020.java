import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean Check(String str) {
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(' || str.charAt(i) == '[' || str.charAt(i) == '{')
                stk.add(str.charAt(i));
            else {
                if (stk.empty())
                    return false;
                if (str.charAt(i) == ')') {
                    if (stk.peek() != '(')
                        return false;
                    else
                        stk.pop();
                } else if (str.charAt(i) == ']') {
                    if (stk.peek() != '[')
                        return false;
                    else
                        stk.pop();
                } else if (str.charAt(i) == '}') {
                    if (stk.peek() != '{')
                        return false;
                    else
                        stk.pop();
                }
            }
        }
        if (stk.size() > 0)
            return false;
        return true;
    }

    static void Solve() {
        String str = sc.next();
        System.out.println(Check(str) ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
