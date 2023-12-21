import java.io.*;
import java.text.*;
import java.util.*;

class Student {
    public String code, name, phoneNumber, email;

    public Student(String code, String name, String phoneNumber, String email) {
        this.code = code;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.email = email;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", this.code, this.name, this.phoneNumber, this.email);
    }
}

public class App {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Student> studentList = new ArrayList<>();
        for (int i = 0; i < n; i++)
            studentList.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        Collections.sort(studentList, new Comparator<Student>() {
            @Override
            public int compare(Student x, Student y) {
                if (!x.name.equals(y.name)) {
                    int lastSpaceX = x.name.lastIndexOf(" "), lastSpaceY = y.name.lastIndexOf(" ");
                    String nameX = x.name.substring(lastSpaceX + 1);
                    String nameY = y.name.substring(lastSpaceY + 1);
                    String surnameX = x.name.substring(0, lastSpaceX);
                    String surnameY = y.name.substring(0, lastSpaceY);
                    if (!nameX.equals(nameY))
                        return nameX.compareTo(nameY);
                    return surnameX.compareTo(surnameY);
                }
                return x.code.compareTo(y.code);
            }
        });
        for (Student x : studentList)
            System.out.println(x);
    }

}
