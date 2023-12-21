import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve(int tc) {
        int n = sc.nextInt();
        int arr[] = new int[n];
        HashMap<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            if (!cnt.containsKey(arr[i]))
                cnt.put(arr[i], 1);
            else
                cnt.put(arr[i], cnt.get(arr[i]) + 1);
        }
        System.out.printf("Test %d:\n", tc);
        for (int i = 0; i < n; i++) {
            if (cnt.containsKey(arr[i])) {
                System.out.printf("%d xuat hien %d lan\n", arr[i], cnt.get(arr[i]));
                cnt.remove(arr[i]);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++)
            Solve(i);
    }
}
