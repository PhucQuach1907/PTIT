import java.util.*;
import java.io.*;;

public class App {
    static int getInt(String s) {
        int ans = 0;
        try {
            ans = Integer.parseInt(s);
        } catch (NumberFormatException e) {
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        long sum = 0;
        while (sc.hasNext()) {
            sum += getInt(sc.next());
        }
        System.out.println(sum);
    }
}
