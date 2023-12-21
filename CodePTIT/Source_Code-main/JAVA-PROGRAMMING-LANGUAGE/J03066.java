import java.math.BigInteger;
import java.util.*;

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        while (true) {
            int n = sc.nextInt();
            if (n == 0)
                break;
            ArrayList<BigInteger> arr = new ArrayList<>();
            for (int i = 0; i < n; i++)
                arr.add(sc.nextBigInteger());
            Collections.sort(arr);
            if (arr.get(0).equals(arr.get(n - 1)))
                System.out.println("BANG NHAU");
            else {
                System.out.println(arr.get(0) + " " + arr.get(n - 1));
            }
        }
    }

}
