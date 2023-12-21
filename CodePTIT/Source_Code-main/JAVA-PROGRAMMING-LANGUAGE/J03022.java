import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String text = "";
        while (sc.hasNext()) {
            String cur = sc.next().toLowerCase();
            text += cur + " ";
        }
        List<String> sentences = new ArrayList<>(Arrays.asList(text.split("[.!?]")));
        for (int i = 0; i < sentences.size(); i++) {
            StringBuilder tmp = new StringBuilder(sentences.get(i).trim());
            if (tmp.length() > 0) {
                tmp.setCharAt(0, Character.toUpperCase(tmp.charAt(0)));
                System.out.println(tmp);
            }
        }
    }
}