import java.util.*;
import java.io.*;

public class App {
    static int n, a[] = new int[25];
    static ArrayList<String> res = new ArrayList<>();

    static void Try(String cur, int start, int prev, int cnt) {
        for (int i = start; i < n; i++) {
            if (a[i] > prev) {
                StringBuilder tmp = new StringBuilder(cur);
                tmp.append(a[i]);
                if (cnt > 0)
                    res.add(tmp.toString());
                tmp.append(" ");
                Try(tmp.toString(), i + 1, a[i], cnt + 1);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DAYSO.in"));
        n = sc.nextInt();
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        Try("", 0, -1, 0);
        Collections.sort(res);
        for (String x : res)
            System.out.println(x);
    }
}
