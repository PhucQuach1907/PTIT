import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean canChangeToPalindrome(String str) {
        int diff = 0, n = str.length();
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(n - i - 1))
                diff++;
        }
        if (diff > 1)
            return false;
        if (diff == 0 && n % 2 == 0)
            return false;
        return true;
    }

    static void Solve() {
        String str = sc.next();
        System.out.println(canChangeToPalindrome(str) ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0) {
            Solve();
        }

    }
}
