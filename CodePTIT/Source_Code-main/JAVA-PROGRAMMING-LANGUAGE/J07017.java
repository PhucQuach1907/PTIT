import java.util.*;
import java.io.*;

class Pair<U, V> {
    public final U first;
    public final V second;

    public Pair(U first, V second) {
        this.first = first;
        this.second = second;
    }

    static boolean checkPrime(int a) {
        if (a < 2)
            return false;
        for (int i = 2; i <= Math.sqrt(a); i++) {
            if (a % i == 0)
                return false;
        }
        return true;
    }

    public boolean isPrime() {
        return checkPrime(Integer.parseInt(this.first.toString()))
                && checkPrime(Integer.parseInt(this.second.toString()));
    }

    public String toString() {
        return String.format("%s %s", this.first.toString(), this.second.toString());
    }
}

public class App {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            boolean check = false;
            for (int i = 2; i <= 2 * Math.sqrt(n); i++) {
                Pair<Integer, Integer> p = new Pair<>(i, n - i);
                if (p.isPrime()) {
                    System.out.println(p);
                    check = true;
                    break;
                }
            }
            if (!check)
                System.out.println(-1);
        }
    }
}
