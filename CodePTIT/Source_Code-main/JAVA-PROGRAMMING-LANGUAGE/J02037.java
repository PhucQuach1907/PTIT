import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean Check(ArrayList<Integer> arr) {
        int odd = 0, even = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i) % 2 == 0)
                even++;
            else
                odd++;
        }
        if (arr.size() % 2 == 1)
            return odd > even;
        return even > odd;
    }

    static void Solve() {
        String str = sc.nextLine();
        List<String> spl = new ArrayList<>(Arrays.asList(str.split(" ")));
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i < spl.size(); i++)
            arr.add(Integer.parseInt(spl.get(i)));
        System.out.println(Check(arr) ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0)
            Solve();
    }
}
