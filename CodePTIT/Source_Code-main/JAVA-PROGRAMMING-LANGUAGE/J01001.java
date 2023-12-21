import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt();
        if (a <= 0 || b <= 0)
            System.out.printf("%d", 0);
        else
            System.out.printf("%d %d", (a + b) * 2, a * b);
    }
}
