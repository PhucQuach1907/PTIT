import java.util.*;

class Student {
    public String code, name, className, email;

    public Student(String code, String name, String className, String email) {
        this.code = code;
        this.name = name;
        this.className = className;
        this.email = email;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", this.code, this.name, this.className, this.email);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        int q = sc.nextInt();
        sc.nextLine();
        while (q-- > 0) {
            String majors = sc.nextLine().toUpperCase();
            System.out.println("DANH SACH SINH VIEN NGANH " + majors + ":");
            for (Student x : arr) {
                if (x.className.charAt(0) == 'E' && (x.code.charAt(5) == 'C' || x.code.charAt(5) == 'A'))
                    continue;
                if (majors.charAt(0) == x.code.charAt(5))
                    System.out.println(x);
            }
        }
    }
}
