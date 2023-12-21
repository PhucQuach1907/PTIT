import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String str = sc.next();
        char sortChar[] = str.toCharArray();
        Arrays.sort(sortChar);
        StringBuilder ans = new StringBuilder("");
        int startIndex = 0;
        for (int i = sortChar.length - 1; i >= 0; i--) {
            int idx = str.indexOf(sortChar[i], startIndex);
            if (idx != -1) {
                ans.append(sortChar[i]);
                startIndex = idx + 1;
            }
        }
        System.out.println(ans);
    }
}