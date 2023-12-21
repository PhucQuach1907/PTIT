import java.lang.ProcessBuilder.Redirect.Type;
import java.util.*;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String str = sc.next();
        ArrayList<String> arr = new ArrayList<String>(Arrays.asList(str.split("")));
        StringBuilder res = new StringBuilder("");
        for (int i = 0; i < arr.size(); i++) {
            String charAt = arr.get(i);
            if (charAt.compareTo("0") == 0 || charAt.compareTo("8") == 0 || charAt.compareTo("9") == 0)
                res.append(0);
            else if (charAt.compareTo("1") == 0)
                res.append(1);
            else {
                System.out.println("INVALID");
                return;
            }
        }
        long ans = Long.parseLong(res.toString());
        if (ans == 0)
            System.out.println("INVALID");
        else
            System.out.println(ans);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
