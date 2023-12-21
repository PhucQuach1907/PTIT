import java.util.*;
import java.io.*;

public class App {
    static boolean isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("SONGUYEN.in"));
        List<Integer> arr = (ArrayList<Integer>) ois.readObject();
        SortedMap<Integer, Integer> cnt = new TreeMap<>();
        for (Integer x : arr) {
            if (isPrime(x)) {
                if (cnt.containsKey(x))
                    cnt.put(x, cnt.get(x) + 1);
                else
                    cnt.put(x, 1);
            }
        }
        cnt.forEach((key, value) -> {
            System.out.printf("%d %d\n", key, value);
        });
    }
}
