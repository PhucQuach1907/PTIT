import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        for (int i = 0; i < n - 1; i++) {
            int val = arr[i], pos = i;
            for (int j = i + 1; j < n; j++) {
                {
                    if (arr[j] < val) {
                        val = arr[j];
                        pos = j;
                    }
                }
            }
            int tmp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = tmp;
            System.out.printf("Buoc %d: ", i + 1);
            for (int j = 0; j < n; j++)
                System.out.printf("%d ", arr[j]);
            System.out.println();
        }
    }
}
