import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean isPalindrome(String s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1))
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        HashMap<String, Integer> cnt = new HashMap<>();
        ArrayList<String> ans = new ArrayList<>();
        int maxLength = 0;
        while (sc.hasNext()) {
            String tmp = sc.next();
            if (isPalindrome(tmp)) {
                if (tmp.length() > maxLength) {
                    ans.clear();
                    ans.add(tmp);
                    maxLength = tmp.length();
                } else if (tmp.length() == maxLength)
                    ans.add(tmp);
                if (!cnt.containsKey(tmp))
                    cnt.put(tmp, 1);
                else
                    cnt.put(tmp, cnt.get(tmp) + 1);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (cnt.containsKey(ans.get(i))) {
                System.out.printf("%s %d\n", ans.get(i), cnt.get(ans.get(i)));
                cnt.remove(ans.get(i));
            }
        }
    }
}