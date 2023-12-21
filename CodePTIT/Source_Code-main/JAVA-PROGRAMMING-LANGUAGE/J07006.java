import java.util.*;
import java.io.*;

public class App {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("DATA.in"));
        List<Integer> arr = (ArrayList<Integer>) ois.readObject();
        int[] cnt = new int[1000];
        for (Integer i : arr) {
            cnt[i]++;
        }
        for (int i = 0; i < 1000; i++) {
            if (cnt[i] > 0) {
                System.out.println(i + " " + cnt[i]);
            }
        }
    }
}
