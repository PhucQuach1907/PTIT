import java.io.File;
import java.util.*;

public class App {
    static long Calc(long a, long b, char x) {
        if (x == '+')
            return (a + b);
        else if (x == '-')
            return (a - b);
        else if (x == '*')
            return (a * b);
        return (a / b);
    }

    static boolean isOperator(char c) {
        return (c != '+' && c != '-' && c != '*' && c != '/' ? false : true);
    }

    static String toSuffix(String s) {
        HashMap<Character, Integer> pri = new HashMap<>();
        pri.put('+', 1);
        pri.put('-', 1);
        pri.put('*', 2);
        pri.put('/', 2);
        pri.put('%', 2);
        pri.put('^', 3);
        pri.put('(', -1);
        StringBuilder res = new StringBuilder("");
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                stk.add(s.charAt(i));
            else if (s.charAt(i) == ')') {
                while (!stk.empty() && stk.peek() != '(') {
                    res.append(stk.pop());
                }
                stk.pop();
            } else if (s.charAt(i) == 'A')
                res.append(s.charAt(i));
            else {
                while (!stk.empty() && pri.get(s.charAt(i)) <= pri.get(stk.peek())
                        && isOperator(stk.peek())) {
                    res.append(stk.pop());
                }
                stk.add(s.charAt(i));
            }
        }
        while (!stk.empty() && isOperator(stk.peek()))
            res.append(stk.pop());
        return res.toString();
    }

    static void Solve(String s) {
        ArrayList<String> num = new ArrayList<>(Arrays.asList(s.split("[()\\+\\-\\*\\/]")));
        while (num.contains(""))
            num.remove(num.indexOf(""));
        StringBuilder tmp = new StringBuilder(s);
        for (String x : num) {
            int pos = tmp.indexOf(x);
            tmp.replace(pos, pos + x.length(), "A");
        }
        s = tmp.toString();
        String suff = toSuffix(s);
        Stack<Long> stk = new Stack<>();
        int numIdx = 0;
        for (int i = 0; i < suff.length(); i++) {
            if (suff.charAt(i) == 'A') {
                stk.add(Long.parseLong(num.get(numIdx)));
                numIdx++;
                continue;
            }
            long n2 = stk.pop(), n1 = stk.pop();
            stk.add(Calc(n1, n2, suff.charAt(i)));
        }
        System.out.println(stk.peek());
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("BIEUTHUC.in"));
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            Solve(s);
        }
    }
}
