import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static boolean isPalindrome(String str) {
        ArrayList<String> arr = new ArrayList<>(Arrays.asList(str.split("")));
        ArrayList<String> rev = new ArrayList<>(Collections.nCopies(arr.size(), ""));
        Collections.copy(rev, arr);
        Collections.reverse(rev);
        return arr.equals(rev);
    }

    static void Solve() {
        String str = sc.next().toUpperCase();
        String deCode = "";
        for (int i = 0; i < str.length(); i++) {
            char cur = str.charAt(i);
            if (cur == 'A' || cur == 'B' || cur == 'C')
                deCode += "2";
            else if (cur == 'D' || cur == 'E' || cur == 'F')
                deCode += "3";
            else if (cur == 'G' || cur == 'H' || cur == 'I')
                deCode += "4";
            else if (cur == 'J' || cur == 'K' || cur == 'L')
                deCode += "5";
            else if (cur == 'M' || cur == 'N' || cur == 'O')
                deCode += "6";
            else if (cur == 'P' || cur == 'Q' || cur == 'R' || cur == 'S')
                deCode += "7";
            else if (cur == 'T' || cur == 'U' || cur == 'V')
                deCode += "8";
            else
                deCode += "9";
        }
        System.out.println(isPalindrome(deCode) ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
