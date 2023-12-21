import java.io.*;
import java.util.*;

public class App {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("MONHOC.in"));
        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            String tmp = sc.nextLine();
        }
        sc = new Scanner(new File("GIANGVIEN.in"));
        n = sc.nextInt();
        sc.nextLine();
        HashMap<String, String> hashLecturer = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String tmp = sc.nextLine();
            hashLecturer.put(tmp.substring(0, tmp.indexOf(" ")), tmp.substring(tmp.indexOf(" ") + 1));
        }
        sc = new Scanner(new File("GIOCHUAN.in"));
        n = sc.nextInt();
        ArrayList<String> diff = new ArrayList<>();
        HashMap<String, Double> res = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String code = sc.next(), codeSubject = sc.next();
            double hoursTeaching = sc.nextDouble();
            String name = hashLecturer.get(code);
            if (!res.containsKey(name)) {
                diff.add(name);
                res.put(name, hoursTeaching);
            } else {
                res.put(name, res.get(name) + hoursTeaching);
            }
        }
        for (String x : diff)
            System.out.printf("%s %.2f\n", x, res.get(x));
    }

}