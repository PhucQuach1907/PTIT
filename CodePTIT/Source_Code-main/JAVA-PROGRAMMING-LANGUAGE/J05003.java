import java.util.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;

class Student {
    private String name, code, DOB, className;
    private double GPA;

    public Student(int orderNumber, String name, String className, String DOB, double GPA) throws ParseException {
        this.name = name;
        this.className = className;
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        this.DOB = formatter.format(formatter.parse(DOB));
        this.GPA = GPA;
        this.code = "B20DCCN" + String.format("%03d", orderNumber);
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %.2f", this.code, this.name, this.className, this.DOB, this.GPA);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Student(i, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextDouble()));
        }
        for (Student x : arr)
            System.out.println(x);
    }
}
