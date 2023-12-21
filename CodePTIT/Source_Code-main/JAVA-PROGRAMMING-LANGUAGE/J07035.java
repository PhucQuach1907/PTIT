import java.io.*;
import java.util.*;

class Student {
    public String code, name, className, email;

    public Student(String code, String name, String className, String email) {
        this.code = code;
        this.name = getFormattedName(name);
        this.className = className;
        this.email = email;
    }

    public String getFormattedName(String nm) {
        ArrayList<String> tmp = new ArrayList<>(Arrays.asList(nm.trim().toLowerCase().split("\\s+")));
        StringBuilder formattedName = new StringBuilder("");
        for (int i = 0; i < tmp.size(); i++) {
            StringBuilder w = new StringBuilder(tmp.get(i));
            w.setCharAt(0, Character.toUpperCase(w.charAt(0)));
            formattedName.append(w + " ");
        }
        return formattedName.toString().trim();
    }
}

class Subject {
    public String code, name, courseLoad;

    public Subject(String code, String name, String courseLoad) {
        this.code = code;
        this.name = name;
        this.courseLoad = courseLoad;
    }
}

class Transcript {
    public String studentCode, studentName, studentClassName, point;

    public Transcript(String studentCode, String studentName, String studentClassName, String point) {
        this.studentCode = studentCode;
        this.studentName = studentName;
        this.studentClassName = studentClassName;
        this.point = point;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", studentCode, studentName, studentClassName, point);
    }
}

public class App {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int n = sc.nextInt();
        sc.nextLine();
        HashMap<String, Student> hashStudent = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String code = sc.nextLine(), name = sc.nextLine(), className = sc.nextLine(),
                    email = sc.nextLine();
            hashStudent.put(code, new Student(code, name, className, email));
        }
        sc = new Scanner(new File("MONHOC.in"));
        n = sc.nextInt();
        sc.nextLine();
        HashMap<String, Subject> hashSubject = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String code = sc.nextLine(), name = sc.nextLine(), courseLoad = sc.nextLine();
            hashSubject.put(code, new Subject(code, name, courseLoad));
        }
        sc = new Scanner(new File("BANGDIEM.in"));
        n = sc.nextInt();
        ArrayList<ArrayList<String>> data = new ArrayList<>();
        for (int i = 0; i < n; i++)
            data.add(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            data.get(i).add(sc.next());
            data.get(i).add(sc.next());
            data.get(i).add(sc.next());
        }
        int q = sc.nextInt();
        while (q-- > 0) {
            String codeSubject = sc.next();
            ArrayList<Transcript> res = new ArrayList<>();
            for (ArrayList<String> x : data) {
                if (x.get(1).equals(codeSubject)) {
                    String tmp = x.get(0);
                    res.add(new Transcript(tmp, hashStudent.get(tmp).name, hashStudent.get(tmp).className, x.get(2)));
                }
            }
            res.sort((x, y) -> {
                double p1 = Double.parseDouble(x.point), p2 = Double.parseDouble(y.point);
                if (p1 != p2) {
                    if (p1 > p2)
                        return -1;
                    return 1;
                }
                return x.studentCode.compareTo(y.studentCode);
            });
            System.out.printf("BANG DIEM MON %s:\n", hashSubject.get(codeSubject).name);
            for (Transcript x : res)
                System.out.println(x);
        }
    }

}
