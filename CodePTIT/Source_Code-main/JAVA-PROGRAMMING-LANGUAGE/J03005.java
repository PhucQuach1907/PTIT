import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String name = sc.nextLine().toLowerCase();
        ArrayList<String> arr = new ArrayList<>(Arrays.asList(name.split("\\s+")));
        if (arr.get(0).length() == 0)
            arr.remove(0);
        for (int i = 1; i < arr.size(); i++) {
            StringBuilder tmp = new StringBuilder(arr.get(i));
            tmp.setCharAt(0, Character.toUpperCase(tmp.charAt(0)));
            System.out.printf("%s%s", tmp, i != arr.size() - 1 ? " " : ", ");
        }
        System.out.println(arr.get(0).toUpperCase());
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0)
            Solve();
    }
}
