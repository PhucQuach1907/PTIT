import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static String Solve(String str) {
        if (str.charAt(0) == '0')
            return "INVALID";
        int even = 0, odd = 0;
        for (int i = 0; i < str.length(); i++) {
            if (!Character.isDigit(str.charAt(i)))
                return "INVALID";
            int num = str.charAt(i) - '0';
            if (num % 2 == 0)
                even++;
            else
                odd++;
        }
        if ((str.length() % 2 == 0 && even > odd) || (str.length() % 2 == 1 && even < odd))
            return "YES";
        return "NO";
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0) {
            String str = sc.next();
            System.out.println(Solve(str));
        }

    }
}
