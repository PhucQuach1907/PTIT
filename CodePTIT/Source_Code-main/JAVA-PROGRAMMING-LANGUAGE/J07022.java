import java.util.*;
import java.io.*;;

public class App {
    static boolean isInteger(String s) {
        int ans = 0;
        try {
            ans = Integer.parseInt(s);
        } catch (NumberFormatException e) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        ArrayList<String> res = new ArrayList<>();
        while (sc.hasNext()) {
            String s = sc.next();
            if (!isInteger(s))
                res.add(s);
        }
        Collections.sort(res);
        for (String x : res)
            System.out.printf("%s ", x);
    }
}
