import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean Check(ArrayList<String> arr) {
        if (!arr.get(0).equals("8") || !arr.get(arr.size() - 1).equals("8"))
            return false;
        ArrayList<String> rev = new ArrayList<>(Collections.nCopies(arr.size(), ""));
        Collections.copy(rev, arr);
        if (!arr.equals(rev))
            return false;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
            sum += Integer.parseInt(arr.get(i));
        return (sum % 10 == 0);
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
