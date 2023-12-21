import java.util.*;

class Lecturer {
    public String code, name, majors;

    public Lecturer(int orderNumber, String name, String majors) {
        this.code = "GV" + String.format("%02d", orderNumber);
        this.name = name;
        this.majors = majors;
    }

    public String getAcronymOfMajors() {
        String res = "";
        for (int i = 0; i < this.majors.length(); i++) {
            if (i == 0 || this.majors.charAt(i - 1) == ' ')
                res += Character.toUpperCase(majors.charAt(i));
        }
        return res;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s", this.code, this.name, this.getAcronymOfMajors());
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Lecturer> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            arr.add(new Lecturer(i, sc.nextLine(), sc.nextLine()));
        int q = sc.nextInt();
        sc.nextLine();
        while (q-- > 0) {
            String keyWord = sc.nextLine();
            System.out.println("DANH SACH GIANG VIEN THEO TU KHOA " + keyWord + ":");
            for (Lecturer x : arr) {
                if (x.name.toLowerCase().contains(keyWord.toLowerCase()))
                    System.out.println(x);
            }
        }
    }
}