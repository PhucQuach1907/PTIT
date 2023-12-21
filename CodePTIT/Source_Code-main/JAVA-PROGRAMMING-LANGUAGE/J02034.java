import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        List<Integer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }
        int cnt = 0;
        for (int i = 1; i < arr.get(arr.size() - 1); i++) {
            if (!arr.contains(i)) {
                cnt++;
                System.out.println(i);
            }
        }
        if (cnt == 0)
            System.out.println("Excellent!");
    }
}
