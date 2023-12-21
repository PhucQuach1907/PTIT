import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean Check(ArrayList<String> arr) {
        ArrayList<String> rev = new ArrayList<>(Collections.nCopies(arr.size(), ""));
        Collections.copy(rev, arr);
        Collections.reverse(rev);
        if (!arr.equals(rev))
            return false;
        for (int i = 0; i < arr.size(); i++) {
            int tmp = Integer.parseInt(arr.get(i));
            if (tmp != 2 && tmp != 3 && tmp != 5 && tmp != 7)
                return false;
        }
        return true;
    }

    static void Solve() {
        String name = sc.next();
        ArrayList<String> arr = new ArrayList<>(Arrays.asList(name.split("")));
        System.out.println(Check(arr) ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
