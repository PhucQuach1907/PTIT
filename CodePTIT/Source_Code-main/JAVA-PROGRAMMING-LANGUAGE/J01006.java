import java.util.*;

public class App {
    public static void main(String[] args) {
        long fibo[] = new long[94];
        fibo[1] = fibo[2] = 1;
        for (int i = 3; i <= 92; i++)
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            System.out.printf("%d\n", fibo[n]);
        }
    }
}
