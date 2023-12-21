import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        List<Integer> myArr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            myArr.add(a[i]);
            Collections.sort(myArr);
            System.out.printf("Buoc %d: ", i);
            for (Integer x : myArr)
                System.out.printf("%d ", x);
            System.out.println();
        }
    }
}