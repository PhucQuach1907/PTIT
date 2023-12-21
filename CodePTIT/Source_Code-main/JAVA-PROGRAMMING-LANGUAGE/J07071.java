import java.io.*;
import java.text.*;
import java.util.*;

public class App {
    static String acronym(String str) {
        StringBuilder sb = new StringBuilder("");
        sb.append(str.charAt(0));
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i - 1) == ' ')
                sb.append(str.charAt(i));
        }
        return sb.toString();
    }

    static boolean isMatched(String x, String y) {
        if (x.length() != y.length())
            return false;
        for (int i = 0; i < x.length(); i++) {
            if (x.charAt(i) != '*') {
                if (x.charAt(i) != y.charAt(i))
                    return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("DANHSACH.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<String> nameList = new ArrayList<>();
        for (int i = 0; i < n; i++)
            nameList.add(sc.nextLine());
        HashMap<String, ArrayList<String>> myMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String name = nameList.get(i);
            String acronymName = acronym(name);
            if (!myMap.containsKey(acronymName))
                myMap.put(acronymName, new ArrayList<>());
            myMap.get(acronymName).add(name);
        }
        int q = sc.nextInt();
        while (q-- > 0) {
            String tmp = sc.next();
            StringBuilder str = new StringBuilder("");
            for (int i = 0; i < tmp.length(); i++) {
                if (tmp.charAt(i) != '.')
                    str.append(tmp.charAt(i));
            }
            ArrayList<String> ans = new ArrayList<>();
            myMap.forEach((key, value) -> {
                if (isMatched(str.toString(), key))
                    ans.addAll(value);
            });
            Collections.sort(ans, new Comparator<String>() {
                @Override
                public int compare(String x, String y) {
                    int lastSpaceX = x.lastIndexOf(" "), lastSpaceY = y.lastIndexOf(" ");
                    String nameX = x.substring(lastSpaceX + 1);
                    String nameY = y.substring(lastSpaceY + 1);
                    String surnameX = x.substring(0, lastSpaceX);
                    String surnameY = y.substring(0, lastSpaceY);
                    if (!nameX.equals(nameY))
                        return nameX.compareTo(nameY);
                    return surnameX.compareTo(surnameY);
                }
            });
            for (String x : ans)
                System.out.println(x);
        }
    }

}
