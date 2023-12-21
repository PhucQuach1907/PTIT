import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int n = sc.nextInt();
        Queue<String> q = new LinkedList<>();
        ArrayList<String> res = new ArrayList<>();
        q.add("6");
        q.add("8");
        while (!q.isEmpty()) {
            String cur = q.remove();
            if (cur.length() > n)
                break;
            res.add(cur);
            q.add(cur + "6");
            q.add(cur + "8");
        }
        System.out.println(res.size());
        for (int i = res.size() - 1; i >= 0; i--)
            System.out.printf("%s ", res.get(i));
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
