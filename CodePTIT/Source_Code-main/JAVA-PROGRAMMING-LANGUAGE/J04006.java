import java.util.*;
import java.text.SimpleDateFormat;
import static java.lang.Math.*;

class Student {
    private String name, code, DOB, className;
    private double GPA;

    public Student(String name, String className, String DOB, double GPA) {
        this.name = name;
        this.className = className;
        this.DOB = DOB;
        this.GPA = GPA;
        this.code = "B20DCCN001";
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %.2f", this.code, this.name, this.className, this.DOB, this.GPA);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        String name = sc.nextLine();
        String className = sc.next();
        String DOB = sc.next();
        DOB = formatter.format(formatter.parse(DOB));
        double GPA = sc.nextDouble();
        Student st = new Student(name, className, DOB, GPA);
        System.out.println(st);
    }
}
