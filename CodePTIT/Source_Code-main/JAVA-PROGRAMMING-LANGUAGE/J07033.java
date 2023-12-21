import java.util.*;
import java.io.*;

class Student {
    public String code, name, className, email;

    public Student(String code, String name, String className, String email) {
        this.code = code;
        this.name = name;
        this.className = className;
        this.email = email;
    }

    public String nameFormatted() {
        ArrayList<String> spl = new ArrayList<>(Arrays.asList(this.name.trim().toLowerCase().split("\\s+")));
        String res = "";
        for (int i = 0; i < spl.size(); i++) {
            StringBuilder tmp = new StringBuilder(spl.get(i));
            tmp.setCharAt(0, Character.toUpperCase(tmp.charAt(0)));
            res += tmp.toString() + " ";
        }
        return res;
    }

    public String toString() {
        return String.format("%s %s%s %s", this.code, this.nameFormatted(), this.className, this.email);
    }
}

public class App {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        Collections.sort(arr, new Comparator<Student>() {
            @Override
            public int compare(Student a, Student b) {
                return a.code.compareTo(b.code);
            }
        });
        for (Student x : arr)
            System.out.println(x);
    }
}
