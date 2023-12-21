import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String name = sc.next();
        ArrayList<String> arr = new ArrayList<>(Arrays.asList(name.split("")));
        ArrayList<String> rev = new ArrayList<>(Collections.nCopies(arr.size(), ""));
        Collections.copy(rev, arr);
        if (!arr.equals(rev)) {
            System.out.println("NO");
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (Integer.parseInt(arr.get(i)) % 2 != 0) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
