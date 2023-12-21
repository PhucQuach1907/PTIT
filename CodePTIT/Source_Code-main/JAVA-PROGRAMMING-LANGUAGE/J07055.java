import java.io.*;
import java.text.*;
import java.util.*;

class Student implements Comparable<Student> {
    public String code, name;
    public int practice, practiceOnline, exam;

    public Student(int orderNumber, String name, int practice, int practiceOnline, int exam) {
        this.code = "SV" + String.format("%02d", orderNumber);
        this.name = name;
        this.practice = practice;
        this.practiceOnline = practiceOnline;
        this.exam = exam;
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

    public double getFinalPoint() {
        return this.practice * 0.25 + this.practiceOnline * 0.35 + this.exam * 0.4;
    }

    public String getClassification() {
        double mark = this.getFinalPoint();
        if (mark >= 8)
            return "GIOI";
        if (mark >= 6.5)
            return "KHA";
        if (mark >= 5)
            return "TRUNG BINH";
        return "KEM";
    }

    @Override
    public int compareTo(Student other) {
        if (this.getFinalPoint() > other.getFinalPoint())
            return -1;
        return 1;
    }

    public String toString() {
        return String.format("%s %s %.2f %s", this.code, this.getFormattedName(), this.getFinalPoint(),
                this.getClassification());
    }
}

public class App {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("BANGDIEM.in"));
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Student(i + 1, sc.nextLine(), sc.nextInt(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(arr);
        for (Student x : arr)
            System.out.println(x);
    }

}
