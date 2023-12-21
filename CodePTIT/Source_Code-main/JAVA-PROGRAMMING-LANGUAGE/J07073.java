import java.io.*;
import java.text.*;
import java.util.*;

class Subject implements Comparable<Subject> {
    private String code, name, theoryForm, practiceForm;
    private int courseLoad;

    public Subject(String code, String name, String courseLoad, String theoryForm, String practiceForm) {
        this.code = code;
        this.name = name;
        this.courseLoad = Integer.parseInt(courseLoad);
        this.theoryForm = theoryForm;
        this.practiceForm = practiceForm;
    }

    public boolean isPracticeOnline() {
        return (this.practiceForm.equals("Truc tuyen") || this.practiceForm.endsWith(".ptit.edu.vn"));
    }

    @Override
    public int compareTo(Subject other) {
        return this.code.compareTo(other.code);
    }

    public String toString() {
        return String.format("%s %s %d %s %s", this.code, this.name, this.courseLoad, this.theoryForm,
                this.practiceForm);
    }
}

public class App {

    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("MONHOC.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Subject> subjectList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            subjectList.add(new Subject(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        ArrayList<Subject> res = new ArrayList<>();
        for (Subject x : subjectList)
            if (x.isPracticeOnline())
                res.add(x);
        Collections.sort(res);
        for (Subject x : res)
            System.out.println(x);
    }

}
