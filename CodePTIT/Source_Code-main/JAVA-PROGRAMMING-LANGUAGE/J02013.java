import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        List<Integer> myArr = new ArrayList<>(Collections.nCopies(n, 0));
        for (int i = 0; i < n; i++) {
            myArr.set(i, sc.nextInt());
        }
        int step = 1;
        while (true) {
            boolean isSwap = false;
            for (int i = 1; i < n; i++) {
                if (myArr.get(i) < myArr.get(i - 1)) {
                    Collections.swap(myArr, i, i - 1);
                    isSwap = true;
                }
            }
            if (!isSwap)
                break;
            System.out.printf("Buoc %d: ", step);
            step++;
            for (int i = 0; i < n; i++)
                System.out.printf("%d ", myArr.get(i));
            System.out.println();
        }
    }
}