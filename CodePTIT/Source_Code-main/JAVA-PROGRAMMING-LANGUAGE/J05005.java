import java.util.*;
import java.text.*;
import java.io.*;

class Student implements Comparable<Student> {
    private String code, name, className, DOB;
    private double GPA;

    public Student(int orderNumber, String name, String className, String DOB, double GPA) throws ParseException {
        this.code = "B20DCCN" + String.format("%03d", orderNumber);
        this.name = name;
        this.className = className;
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
        this.DOB = formatter.format(formatter.parse(DOB));
        this.GPA = GPA;
    }

    public String getFormattedName() {
        ArrayList<String> tmp = new ArrayList<>(Arrays.asList(this.name.trim().toLowerCase().split("\\s+")));
        StringBuilder formattedName = new StringBuilder("");
        for (int i = 0; i < tmp.size(); i++) {
            StringBuilder w = new StringBuilder(tmp.get(i));
            w.setCharAt(0, Character.toUpperCase(w.charAt(0)));
            formattedName.append(w + " ");
        }
        return formattedName.toString().trim();
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %.2f", this.code, this.getFormattedName(), this.className, this.DOB,
                this.GPA);
    }

    public int compareTo(Student other) {
        if (this.GPA > other.GPA)
            return -1;
        return 1;
    }
}

public class App {
    public static void main(String[] args) throws ParseException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Student(i + 1, sc.nextLine(), sc.next(), sc.next(), sc.nextDouble()));
        }
        Collections.sort(arr);
        for (Student x : arr)
            System.out.println(x);
    }
}
