import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x = sc.nextInt();
                if (x == 1 && i < j)
                    System.out.printf("(%d,%d)\n", i, j);
            }
        }
    }
}
