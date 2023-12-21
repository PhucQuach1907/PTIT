import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String s = sc.next();
        int k = sc.nextInt();
        HashSet<Character> diff = new HashSet<>();
        for (int i = 0; i < s.length(); i++)
            diff.add(s.charAt(i));
        System.out.println(k < 26 - diff.size() ? "NO" : "YES");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}