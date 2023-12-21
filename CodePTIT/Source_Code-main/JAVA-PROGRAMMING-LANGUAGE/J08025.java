import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        Queue<String> q = new LinkedList<>();
        String s = "", target = "";
        for (int i = 0; i < 6; i++)
            s += Integer.toString(sc.nextInt());
        for (int i = 0; i < 6; i++)
            target += Integer.toString(sc.nextInt());
        q.add(s);
        HashMap<String, Integer> myMap = new HashMap<>();
        myMap.put(s, 0);
        while (!q.isEmpty()) {
            String cur = q.remove();
            if (cur.equals(target)) {
                System.out.println(myMap.get(cur));
                return;
            }
            StringBuilder tmp = new StringBuilder(cur);
            tmp.setCharAt(0, cur.charAt(3));
            tmp.setCharAt(1, cur.charAt(0));
            tmp.setCharAt(4, cur.charAt(1));
            tmp.setCharAt(3, cur.charAt(4));
            if (!myMap.containsKey(tmp.toString())) {
                q.add(tmp.toString());
                myMap.put(tmp.toString(), myMap.get(cur) + 1);
            }
            tmp = new StringBuilder(cur);
            tmp.setCharAt(1, cur.charAt(4));
            tmp.setCharAt(2, cur.charAt(1));
            tmp.setCharAt(5, cur.charAt(2));
            tmp.setCharAt(4, cur.charAt(5));
            if (!myMap.containsKey(tmp.toString())) {
                q.add(tmp.toString());
                myMap.put(tmp.toString(), myMap.get(cur) + 1);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
