import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static String Smallest(int m, int s) {
        if (s > 9 * m || (m > 1 && s == 0))
            return "-1";
        String ans = "";
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < 10; j++) {
                double tg = (s - j) * 1.0 / (m - i);
                if (i == 1 && tg <= 9 && j != 0) {
                    ans += Integer.toString(j);
                    s -= j;
                    break;
                } else if (tg <= 9 && i > 1) {
                    ans += Integer.toString(j);
                    s -= j;
                    break;
                }
            }
        }
        ans += Integer.toString(s);
        return ans;
    }

    static String Biggest(int m, int s) {
        if (s > 9 * m || (m > 1 && s == 0))
            return "-1";
        String ans = "";
        for (int i = 1; i <= m; i++) {
            if (s >= 9) {
                ans += "9";
                s -= 9;
            } else if (s > 0 && s < 9) {
                ans += Integer.toString(s);
                s -= s;
            } else
                ans += "0";
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        int m = sc.nextInt(), s = sc.nextInt();
        System.out.println(Smallest(m, s) + " " + Biggest(m, s));
    }
}
