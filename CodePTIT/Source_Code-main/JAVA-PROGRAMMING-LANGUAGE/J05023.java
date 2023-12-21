import java.util.*;
import java.text.*;
import java.io.*;

class Student {
    private String code, name, className, email;

    public Student(String code, String name, String className, String email) {
        this.code = code;
        this.name = name;
        this.className = className;
        this.email = email;
    }

    public boolean isMatchedYear(String yearQuery) {
        return yearQuery.endsWith(this.className.substring(1, 3));
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
        while (q-- > 0) {
            String yearQuery = sc.next();
            ArrayList<Student> res = new ArrayList<>();
            for (Student x : arr) {
                if (x.isMatchedYear(yearQuery))
                    res.add(x);
            }
            System.out.println("DANH SACH SINH VIEN KHOA " + yearQuery + ":");
            for (Student x : res)
                System.out.println(x);
        }
    }
}
