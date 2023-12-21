import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        String s = sc.next();
        int res = 0;
        ArrayList<Character> element = new ArrayList<>();
        ArrayList<Integer> idx = new ArrayList<>();
        element.add('-');
        idx.add(-1);
        for (int i = 0; i < s.length(); i++) {
            element.add(s.charAt(i));
            idx.add(i);
            while (element.size() >= 3 && element.get(element.size() - 1) == '0'
                    && element.get(element.size() - 2) == '0' && element.get(element.size() - 3) == '1') {
                element.remove(element.size() - 1);
                element.remove(element.size() - 1);
                element.remove(element.size() - 1);
                idx.remove(idx.size() - 1);
                idx.remove(idx.size() - 1);
                idx.remove(idx.size() - 1);
            }
            if (!idx.isEmpty())
                res = Math.max(res, i - idx.get(idx.size() - 1));
            if (idx.isEmpty()) {
                element.add('-');
                idx.add(-1);
            }
        }
        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}