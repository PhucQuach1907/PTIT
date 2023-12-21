import java.util.*;

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        while (sc.hasNextLine()) {
            String inp = sc.nextLine().trim().toLowerCase();
            ArrayList<String> word = new ArrayList<>(Arrays.asList(inp.split("\\s+")));
            String s = "";
            for (String x : word)
                s += x + " ";
            StringBuilder nmc = new StringBuilder(s);
            for (int i = 0; i < nmc.length() - 1; i++) {
                if (nmc.charAt(i) == ' '
                        && (nmc.charAt(i + 1) == '!' || nmc.charAt(i + 1) == '.' || nmc.charAt(i + 1) == '?')) {
                    nmc.deleteCharAt(i);
                    i--;
                }
            }
            s = nmc.toString().trim();
            char lastChar = s.charAt(s.length() - 1);
            if (lastChar != '.' && lastChar != '?' && lastChar != '!')
                s += ".";
            ArrayList<String> sentences = new ArrayList<>(Arrays.asList(s.split("[.?!]")));
            for (int i = 0; i < sentences.size(); i++)
                sentences.set(i, sentences.get(i).trim());
            for (int i = 0; i < sentences.size(); i++) {
                StringBuilder tmp = new StringBuilder(sentences.get(i));
                tmp.append(s.charAt(s.indexOf(sentences.get(i)) +
                        sentences.get(i).length()));
                tmp.setCharAt(0, Character.toUpperCase(tmp.charAt(0)));
                System.out.println(tmp.toString());
            }
        }
    }
}
