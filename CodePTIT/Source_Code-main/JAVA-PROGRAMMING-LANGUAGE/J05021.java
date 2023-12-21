import java.util.*;
import java.text.*;
import java.io.*;

class Student implements Comparable<Student> {
    private String code, name, className, email;

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

    public int compareTo(Student other) {
        return this.code.compareTo(other.code);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        ArrayList<Student> arr = new ArrayList<>();
        int line = 1;
        String code = "", name = "", className = "", email = "";
        while (sc.hasNextLine()) {
            if (line % 4 == 1)
                code = sc.nextLine();
            else if (line % 4 == 2)
                name = sc.nextLine();
            else if (line % 4 == 3)
                className = sc.nextLine();
            else {
                email = sc.nextLine();
                arr.add(new Student(code, name, className, email));
            }
            line++;
        }
        Collections.sort(arr);
        for (Student x : arr)
            System.out.println(x);
    }
}
