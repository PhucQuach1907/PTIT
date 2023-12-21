import java.math.BigInteger;
import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++)
            adj.add(new ArrayList<>());
        for (int i = 0; i < n - 1; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (adj.get(i).size() > 1)
                cnt++;
        }
        System.out.printf(cnt == 1 ? "Yes" : "No");
    }
}
