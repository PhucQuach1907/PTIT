import java.io.*;
import java.text.*;
import java.util.*;

public class App {
    static String getFormattedName(String name) {
        ArrayList<String> tmp = new ArrayList<>(Arrays.asList(name.trim().toLowerCase().split("\\s+")));
        StringBuilder formattedName = new StringBuilder("");
        for (int i = 0; i < tmp.size(); i++) {
            StringBuilder w = new StringBuilder(tmp.get(i));
            w.setCharAt(0, Character.toUpperCase(w.charAt(0)));
            formattedName.append(w + " ");
        }
        return formattedName.toString().trim();
    }

    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("DANHSACH.in"));
        ArrayList<String> listName = new ArrayList<>();
        while (sc.hasNextLine()) {
            String name = sc.nextLine();
            listName.add(getFormattedName(name));
        }
        Collections.sort(listName, new Comparator<String>() {
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
        for (String x : listName)
            System.out.println(x);
    }

}
