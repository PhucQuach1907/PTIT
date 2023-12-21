import java.util.*;
import java.io.*;

public class App {
    static String nameFormatted(String name) {
        ArrayList<String> word = new ArrayList<>(Arrays.asList(name.split("\\s+")));
        StringBuilder res = new StringBuilder("");
        for (int i = 0; i < word.size(); i++) {
            StringBuilder tmp = new StringBuilder(word.get(i));
            tmp.setCharAt(0, Character.toUpperCase(tmp.charAt(0)));
            res.append(tmp.append(" "));
        }
        return res.toString();
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DATA.in"));
        while (true) {
            String name = sc.nextLine().trim().toLowerCase();
            if (name.equals("end"))
                break;
            System.out.println(nameFormatted(name));
        }
    }
}
