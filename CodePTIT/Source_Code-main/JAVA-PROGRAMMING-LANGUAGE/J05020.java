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
        if (!this.className.equals(other.className))
            return this.className.compareTo(other.className);
        return this.code.compareTo(other.code);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            arr.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        Collections.sort(arr);
        for (Student x : arr)
            System.out.println(x);
    }
}
