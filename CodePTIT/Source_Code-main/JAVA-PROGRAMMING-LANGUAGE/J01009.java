import java.util.*;

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        long n = sc.nextLong(), res = 0, fact = 1;
        for (long i = 1; i <= n; i++) {
            fact *= i;
            res += fact;
        }
        System.out.printf("%d", res);
    }
}
