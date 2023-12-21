import java.util.*;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            ArrayList<Integer> arr = new ArrayList<Integer>(Collections.nCopies(n, 0));
            for (int i = 0; i < n; i++)
                arr.set(i, sc.nextInt());
            ArrayList<Integer> arrRev = new ArrayList<Integer>(Collections.nCopies(n, 0));
            Collections.copy(arrRev, arr);
            Collections.reverse(arrRev);
            System.out.printf("%s\n", arr.equals(arrRev) ? "YES" : "NO");
        }

    }
}
