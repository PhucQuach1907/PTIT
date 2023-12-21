import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String str = sc.next();
        Stack<Character> stk = new Stack<>(), tmp = new Stack<>();
        for (int i = 0; i < str.length(); i++) {
            char cur = str.charAt(i);
            if (cur == '<') {
                if (!stk.empty())
                    tmp.push(stk.pop());
            } else if (cur == '>') {
                if (!tmp.empty())
                    stk.push(tmp.pop());
            } else if (cur == '-') {
                if (!stk.empty())
                    stk.pop();
            } else
                stk.push(cur);
        }
        while (!tmp.empty())
            stk.push(tmp.pop());
        StringBuilder ans = new StringBuilder("");
        while (!stk.empty())
            ans.append(stk.pop());
        ans.reverse();
        System.out.printf("%s", ans);
    }
}