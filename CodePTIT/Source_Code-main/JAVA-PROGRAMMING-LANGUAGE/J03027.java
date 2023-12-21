import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String s = sc.next();
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (stk.empty()) {
                stk.add(s.charAt(i));
                continue;
            }
            if (stk.peek() == s.charAt(i))
                stk.pop();
            else
                stk.add(s.charAt(i));
        }
        if (stk.size() == 0)
            System.out.println("Empty String");
        else {
            for (int i = 0; i < stk.size(); i++)
                System.out.printf("%s", stk.get(i));
            System.out.println();
        }
    }

    public static void main(String[] args) throws Exception {
        int t = 1;
        while (t-- > 0) {
            Solve();
        }

    }
}
