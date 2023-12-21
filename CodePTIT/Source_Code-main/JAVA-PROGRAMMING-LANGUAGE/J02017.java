import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            if (stk.empty())
                stk.push(x);
            else {
                if ((x + stk.peek()) % 2 == 0)
                    stk.pop();
                else
                    stk.push(x);
            }
        }
        System.out.println(stk.size());
    }
}