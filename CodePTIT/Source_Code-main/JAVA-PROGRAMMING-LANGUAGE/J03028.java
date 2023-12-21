import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        StringBuilder s = new StringBuilder(sc.next());
        int l = 0, r = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (i < n / 2)
                l += s.charAt(i) - 'A';
            else
                r += s.charAt(i) - 'A';
        }
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                char tmp = (char) ((s.charAt(i) - 'A' + l) % 26 + 'A');
                s.setCharAt(i, tmp);
            } else {
                char tmp = (char) ((s.charAt(i) - 'A' + r) % 26 + 'A');
                s.setCharAt(i, tmp);
            }
        }
        for (int i = 0; i < n / 2; i++) {
            char tmp = (char) ((s.charAt(i) - 'A' + s.charAt(i + n / 2) - 'A') % 26 + 'A');
            s.setCharAt(i, tmp);
        }
        System.out.println(s.substring(0, n / 2));
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}