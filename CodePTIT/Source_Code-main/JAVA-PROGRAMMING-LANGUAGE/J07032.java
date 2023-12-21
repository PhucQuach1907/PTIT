import java.util.*;
import java.io.*;

public class App {
    static boolean Check(int n) {
        String tmp = Integer.toString(n);
        int len = tmp.length();
        if (len == 1 || len % 2 == 0)
            return false;
        for (int i = 0; i < len; i++) {
            int num = tmp.charAt(i) - '0';
            if (num % 2 == 0)
                return false;
        }
        for (int i = 0; i < len / 2; i++) {
            if (tmp.charAt(i) != tmp.charAt(len - i - 1))
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("DATA1.in"));
        List<Integer> a = (ArrayList<Integer>) ois.readObject();
        ois = new ObjectInputStream(new FileInputStream("DATA2.in"));
        List<Integer> b = (ArrayList<Integer>) ois.readObject();
        int[] cnt = new int[1000005];
        for (Integer x : a) {
            if (Check(x))
                cnt[x] += 1;
        }
        for (Integer x : b) {
            if (Check(x))
                cnt[x] += 1;
        }
        int d = 0;
        Collections.sort(a);
        Collections.sort(b);
        for (int i = 0; i < a.size(); i++) {
            if (cnt[a.get(i)] > 0) {
                if (Collections.binarySearch(b, a.get(i)) >= 0) {
                    System.out.println(a.get(i) + " " + cnt[a.get(i)]);
                    d++;
                    if (d == 10)
                        break;
                    cnt[a.get(i)] = 0;
                }
            }
        }
    }
}
