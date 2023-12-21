import java.util.*;
import java.io.*;

public class App {
    static void Solve(String str) {
        StringBuilder number = new StringBuilder("");
        int sumDigit = 0;
        for (int i = 0; i < str.length(); i++) {
            if (Character.isDigit(str.charAt(i))) {
                number.append(str.charAt(i));
                sumDigit += str.charAt(i) - '0';
            }
        }
        int start = 0;
        for (int i = 0; i < number.length(); i++) {
            if (number.charAt(i) != '0') {
                start = i;
                break;
            }
        }
        System.out.println(number.substring(start) + " " + sumDigit);
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("DATA.in"));
        List<String> arr = (ArrayList<String>) ois.readObject();
        for (String x : arr)
            Solve(x);
    }
}
