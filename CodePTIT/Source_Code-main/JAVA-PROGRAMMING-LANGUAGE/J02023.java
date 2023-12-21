import java.util.*;
import java.io.*;;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static String Smallest(int m, int s) {
        if (s > 9 * m || (m > 1 && s == 0))
            return "-1";
        StringBuilder ans = new StringBuilder("");
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < 10; j++) {
                double tg = (s - j) * 1.0 / (m - i);
                if (i == 1 && tg <= 9 && j != 0) {
                    ans.append(j);
                    s -= j;
                    break;
                } else if (tg <= 9 && i > 1) {
                    ans.append(j);
                    s -= j;
                    break;
                }
            }
        }
        ans.append(s);
        return ans.toString();
    }

    static String Biggest(int m, int s) {
        if (s > 9 * m || (m > 1 && s == 0))
            return "-1";
        StringBuilder ans = new StringBuilder("");
        for (int i = 1; i <= m; i++) {
            if (s >= 9) {
                ans.append(9);
                s -= 9;
            } else if (s > 0 && s < 9) {
                ans.append(s);
                s -= s;
            } else
                ans.append(0);
        }
        return ans.toString();
    }

    public static void main(String[] args) throws IOException {
        int m = sc.nextInt(), s = sc.nextInt();
        System.out.printf("%s %s", Smallest(m, s), Biggest(m, s));
    }
}