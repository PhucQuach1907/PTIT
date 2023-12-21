import java.io.*;
import java.util.*;
import java.text.*;

class Student {
    private String code, name, DOB, className;
    private double GPA;

    public Student(int orderNumber, String name, String className, String DOB, double GPA) {
        this.code = String.format("B20DCCN%03d", orderNumber);
        this.name = getFormattedName(name);
        this.className = className;
        this.DOB = getFormattedDOB(DOB);
        this.GPA = GPA;
    }

    public String getFormattedName(String s) {
        ArrayList<String> word = new ArrayList<>(Arrays.asList(s.trim().toLowerCase().split("\\s+")));
        StringBuilder res = new StringBuilder("");
        for (int i = 0; i < word.size(); i++) {
            StringBuilder tmp = new StringBuilder(word.get(i));
            tmp.setCharAt(0, Character.toUpperCase(tmp.charAt(0)));
            res.append(tmp.append(" "));
        }
        return res.toString().trim();
    }

    public String getFormattedDOB(String s) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        try {
            return sdf.format(sdf.parse(s));
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return "";
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %.2f", code, name, className, DOB, GPA);
    }
}

public class App {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
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