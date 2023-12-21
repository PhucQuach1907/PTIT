import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble(), b = sc.nextDouble();
        if (a == 0 && b == 0)
            System.out.printf("%s", "VSN");
        else if (a == 0)
            System.out.printf("%s", "VN");
        else
            System.out.printf("%.2f", -b / a);
    }
}
