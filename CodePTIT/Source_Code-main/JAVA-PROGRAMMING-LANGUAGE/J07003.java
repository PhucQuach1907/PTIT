import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class App {
    static void Try(String s) {
        if (s.length() == 1)
            return;
        BigInteger a = new BigInteger(s.substring(0, s.length() / 2));
        BigInteger b = new BigInteger(s.substring(s.length() / 2));
        BigInteger sum = a.add(b);
        System.out.println(sum.toString());
        Try(sum.toString());
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        String s = sc.next();
        Try(s);
    }
}
