import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String s1 = sc.nextLine(), s2 = sc.nextLine();
        ArrayList<String> arr1 = new ArrayList<>(Arrays.asList(s1.split(" ")));
        ArrayList<String> arr2 = new ArrayList<>(Arrays.asList(s2.split(" ")));
        ArrayList<String> res = new ArrayList<>();
        for (int i = 0; i < arr1.size(); i++) {
            if (!arr2.contains(arr1.get(i))) {
                if (!res.contains(arr1.get(i)))
                    res.add(arr1.get(i));
            }
        }
        Collections.sort(res);
        for (String x : res)
            System.out.printf("%s ", x);
        System.out.println();
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0)
            Solve();
    }
}
