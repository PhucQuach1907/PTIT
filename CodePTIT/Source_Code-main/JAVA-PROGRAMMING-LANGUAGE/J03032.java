import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String str = sc.nextLine();
        ArrayList<String> arr = new ArrayList<>(Arrays.asList(str.split(" ")));
        for (int i = 0; i < arr.size(); i++) {
            String tmp = arr.get(i);
            for (int j = tmp.length() - 1; j >= 0; j--)
                System.out.printf("%s", tmp.charAt(j));
            System.out.printf(" ");
        }
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            Solve();
        }

    }
}
