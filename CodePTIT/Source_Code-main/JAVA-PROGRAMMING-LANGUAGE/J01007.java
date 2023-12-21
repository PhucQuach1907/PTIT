import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        ArrayList<Long> fibo = new ArrayList<Long>(Collections.nCopies(94, 0l));
        fibo.set(1, 1l);
        fibo.set(2, 1l);
        for (int i = 3; i <= 93; i++)
            fibo.set(i, fibo.get(i - 2) + fibo.get(i - 1));
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            System.out.printf("%s\n", fibo.contains(n) ? "YES" : "NO");
        }
    }
}
