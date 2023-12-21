import java.util.*;
import java.io.*;

public class App {
    public static void main(String[] args) throws IOException {
        DataInputStream sc = new DataInputStream(new FileInputStream("DATA.IN"));
        int[] cnt = new int[1000];
        for (int i = 0; i < 100000; i++) {
            cnt[sc.readInt()]++;
        }
        for (int i = 0; i < 1000; i++) {
            if (cnt[i] > 0) {
                System.out.println(i + " " + cnt[i]);
            }
        }
    }
}
