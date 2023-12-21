import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String name = sc.nextLine().toLowerCase();
        List<String> arr = Arrays.asList(name.split("\\s+"));
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).length() > 0) {
                StringBuilder tmp = new StringBuilder(arr.get(i));
                tmp.setCharAt(0, Character.toUpperCase(tmp.charAt(0)));
                System.out.printf("%s ", tmp);
            }
        }
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0)
            Solve();
    }
}
