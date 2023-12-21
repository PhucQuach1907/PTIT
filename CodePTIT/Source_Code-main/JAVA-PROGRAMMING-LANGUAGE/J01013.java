import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);
    static boolean[] isPrime = new boolean[2000005];
    static long[] ans = new long[2000005];

    static void init() {
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (long i = 2; i <= 2000005 / 2; i++) {
            if (isPrime[(int) i] == true) {
                for (long j = 2 * i; j < 2000005; j += i) {
                    isPrime[(int) j] = false;
                    long n = j;
                    while (n % i == 0) {
                        ans[(int) j] += i;
                        n /= i;
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        init();
        int t = sc.nextInt();
        long res = 0;
        while (t-- > 0) {
            long x;
            x = sc.nextLong();
            res += (isPrime[(int) x] == true ? x : ans[(int) x]);
        }
        System.out.println(res);
    }
}
