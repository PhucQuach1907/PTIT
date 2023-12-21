import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String s = sc.next();
        if (s.length() < 2)
            System.out.println(Integer.parseInt(s) % 4 == 0 ? 4 : 0);
        else
            System.out.println(Integer.parseInt(s.substring(s.length() - 2)) % 4 == 0 ? 4 : 0);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}