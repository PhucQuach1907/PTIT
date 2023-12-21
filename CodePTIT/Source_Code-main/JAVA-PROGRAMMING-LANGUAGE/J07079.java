import java.util.*;
import java.io.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve(String str) {
        ArrayList<String> res = new ArrayList<>(Arrays.asList(str.split("[2-9]")));
        StringBuilder bin = new StringBuilder("");
        for (String x : res) {
            if (x.length() > 0)
                bin.append(x);
        }
        long dec = Long.parseLong(bin.toString(), 2);
        System.out.println(bin + " " + dec);
    }

    public static void main(String[] args) throws Exception {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("DATA.in"));
        List<String> arr = (ArrayList<String>) ois.readObject();
        for (String x : arr)
            Solve(x);
    }
}
