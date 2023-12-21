import java.util.*;

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int sumofDivisors[] = new int[1000005];
        for (int i = 1; i <= 1000005 / 2; i++) {
            for (int j = 2 * i; j < 1000005; j += i)
                sumofDivisors[j] += i;
        }
        int l = sc.nextInt(), r = sc.nextInt(), res = 0;
        for (int i = l; i <= r; i++)
            res += (sumofDivisors[i] > i ? 1 : 0);
        System.out.println(res);
    }

}