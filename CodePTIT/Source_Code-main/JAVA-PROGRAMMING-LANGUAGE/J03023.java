import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        HashMap<Character, Integer> romVal = new HashMap<>();
        romVal.put('I', 1);
        romVal.put('V', 5);
        romVal.put('X', 10);
        romVal.put('L', 50);
        romVal.put('C', 100);
        romVal.put('D', 500);
        romVal.put('M', 1000);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            int res = 0;
            for (int i = 0; i < s.length(); i++) {
                if (i > 0 && romVal.get(s.charAt(i)) > romVal.get(s.charAt(i - 1)))
                    res += romVal.get(s.charAt(i)) - 2 * romVal.get(s.charAt(i - 1));
                else
                    res += romVal.get(s.charAt(i));
            }
            System.out.println(res);
        }
    }
}
