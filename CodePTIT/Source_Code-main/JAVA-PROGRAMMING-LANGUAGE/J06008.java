import java.util.*;

class Info {
    public String codeLecturer, codeSubject;
    public double hoursTeaching;

    public Info(String codeLecturer, String codeSubject, double hoursTeaching) {
        this.codeLecturer = codeLecturer;
        this.codeSubject = codeSubject;
        this.hoursTeaching = hoursTeaching;
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        sc.nextLine();
        HashMap<String, String> hashSubject = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String tmp = sc.nextLine();
            hashSubject.put(tmp.substring(0, tmp.indexOf(" ")), tmp.substring(tmp.indexOf(" ") + 1));
        }
        n = sc.nextInt();
        sc.nextLine();
        HashMap<String, String> hashLecturer = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String tmp = sc.nextLine();
            hashLecturer.put(tmp.substring(0, tmp.indexOf(" ")), tmp.substring(tmp.indexOf(" ") + 1));
        }
        n = sc.nextInt();
        ArrayList<String> hoursInString = new ArrayList<>();
        ArrayList<Info> arr = new ArrayList<>();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            String codeLecturer = sc.next(), codeSubject = sc.next(), hoursTeaching = sc.next();
            hoursInString.add(hoursTeaching);
            arr.add(new Info(codeLecturer, codeSubject, Double.parseDouble(hoursTeaching)));
        }
        String q = sc.next();
        double total = 0;
        System.out.printf("Giang vien: %s\n", hashLecturer.get(q));
        for (int i = 0; i < n; i++) {
            if (arr.get(i).codeLecturer.equals(q)) {
                System.out.println(hashSubject.get(arr.get(i).codeSubject) + " " + hoursInString.get(i));
                total += arr.get(i).hoursTeaching;
            }
        }
        System.out.printf("Tong: %.2f", total);
    }

}
