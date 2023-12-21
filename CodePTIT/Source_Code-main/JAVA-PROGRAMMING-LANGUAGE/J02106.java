import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int zero = 0, one = 0;
            for (int j = 0; j < 3; j++) {
                int x = sc.nextInt();
                if (x == 1)
                    one++;
                else
                    zero++;
            }
            res += (one > zero ? 1 : 0);
        }
        System.out.printf("%d", res);
    }
}
