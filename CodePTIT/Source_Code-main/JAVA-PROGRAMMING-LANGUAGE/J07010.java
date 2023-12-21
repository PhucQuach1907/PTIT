import java.util.*;
import java.io.*;
import java.text.*;

class Student {
    private String code, name, className, DOB;
    private double GPA;

    public Student(String name, String className, String DOB, double GPA, int orderNumber) throws ParseException {
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

    public static void main(String[] args) throws IOException, ParseException {
        Scanner sc = new Scanner(new File("SV.in"));
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Student(sc.nextLine(), sc.next(), sc.next(), sc.nextDouble(), i));
        }
        for (Student x : arr)
            System.out.println(x);
    }
}
