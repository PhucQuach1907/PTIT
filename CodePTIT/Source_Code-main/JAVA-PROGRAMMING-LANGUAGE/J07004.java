import java.util.*;
import java.io.*;

public class App {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        SortedMap<Integer, Integer> cnt = new TreeMap<>();
        while (sc.hasNextInt()) {
            int num = sc.nextInt();
            if (cnt.containsKey(num))
                cnt.put(num, cnt.get(num) + 1);
            else
                cnt.put(num, 1);
        }
        cnt.forEach((key, value) -> {
            System.out.printf("%d %d\n", key, value);
        });
    }
}
