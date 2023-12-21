import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        long n = sc.nextLong();
        int ans = 0;
        while (n > 0) {
            if (n % 10 == 4 || n % 10 == 7)
                ans++;
            n /= 10;
        }
        System.out.println((ans == 4 || ans == 7) ? "YES" : "NO");
    }
}
