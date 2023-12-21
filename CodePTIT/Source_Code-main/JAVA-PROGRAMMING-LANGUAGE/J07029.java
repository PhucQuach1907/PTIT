import java.util.*;
import java.io.*;

public class App {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        int MAX = (int) 1e6 + 5;
        boolean isPrime[] = new boolean[MAX];
        Arrays.fill(isPrime, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= MAX / 2; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i; j < MAX; j += i)
                    isPrime[j] = false;
            }
        }
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("DATA.in"));
        List<Integer> arr = (ArrayList<Integer>) ois.readObject();
        int[] cnt = new int[MAX + 1];
        for (Integer i : arr) {
            if (isPrime[i])
                cnt[i] += 1;
        }
        int dem = 0;
        for (int i = MAX - 5; i >= 2; i--) {
            if (cnt[i] > 0) {
                System.out.println(i + " " + cnt[i]);
                dem++;
                if (dem == 10) {
                    break;
                }
            }
        }
    }
}
