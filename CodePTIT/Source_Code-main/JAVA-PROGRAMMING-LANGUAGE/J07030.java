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
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("DATA1.in"));
        List<Integer> a = (ArrayList<Integer>) ois.readObject();
        ois = new ObjectInputStream(new FileInputStream("DATA2.in"));
        List<Integer> b = (ArrayList<Integer>) ois.readObject();
        Collections.sort(a);
        Collections.sort(b);
        SortedSet<Integer> mySet = new TreeSet<>();
        for (int i = 0; i < a.size(); i++) {
            int num = a.get(i);
            if (num > 500000)
                break;
            if (mySet.contains(num))
                continue;
            if (isPrime[num]) {
                int tmp = 1000000 - num;
                if (isPrime[tmp]) {
                    if (Collections.binarySearch(b, tmp) >= 0) {
                        System.out.println(num + " " + tmp);
                    }
                }
                mySet.add(num);
            }
        }
    }
}
