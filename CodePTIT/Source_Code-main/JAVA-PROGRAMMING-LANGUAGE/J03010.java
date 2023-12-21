import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);
    static HashMap<String, Integer> myMap = new HashMap<>();

    static void Solve() {
        String str = sc.nextLine().toLowerCase();
        ArrayList<String> arr = new ArrayList<>();
        StringBuilder word = new StringBuilder("");
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) != ' ')
                word.append(str.charAt(i));
            else {
                if (word.length() > 0)
                    arr.add(word.toString());
                word = new StringBuilder("");
            }
        }
        if (word.length() > 0)
            arr.add(word.toString());
        StringBuilder ans = new StringBuilder("");
        ans.append(arr.get(arr.size() - 1));
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr.get(i).length() > 0)
                ans.append(arr.get(i).charAt(0));
        }
        String tmp = ans.toString();
        if (myMap.containsKey(tmp)) {
            myMap.put(tmp, myMap.get(tmp) + 1);
            ans.append(myMap.get(tmp));
        } else
            myMap.put(tmp, 1);
        System.out.printf("%s@ptit.edu.vn\n", ans);
    }

    public static void main(String[] args) throws Exception {
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0)
            Solve();
    }
}
