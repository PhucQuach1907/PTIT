import java.util.*;

public class App {
    public static Boolean Check(ArrayList<Integer> arr) {
        int sum = 0;
        for (int x : arr)
            sum += x;
        if (sum % 10 != 0)
            return false;
        for (int i = 1; i < arr.size(); i++) {
            if (Math.abs(arr.get(i) - arr.get(i - 1)) != 2)
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            long n = sc.nextLong();
            ArrayList<Integer> arr = new ArrayList<Integer>();
            while (n > 0) {
                arr.add((int) (n % 10));
                n /= 10;
            }
            System.out.printf("%s\n", Check(arr) ? "YES" : "NO");
        }

    }
}
