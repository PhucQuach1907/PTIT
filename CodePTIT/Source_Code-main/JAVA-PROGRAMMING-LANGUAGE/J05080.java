import java.util.*;

class Course implements Comparable<Course> {
    public String code, name, group, lecturer;

    public Course(String code, String name, String group, String lecturer) {
        this.code = code;
        this.name = name;
        this.group = group;
        this.lecturer = lecturer;
    }

    @Override
    public int compareTo(Course other) {
        if (!this.code.equals(other.code))
            return this.code.compareTo(other.code);
        return this.group.compareTo(other.group);
    }

    public String toString() {
        return String.format("%s %s %s", code, name, group);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Course> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Course(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        int q = sc.nextInt();
        sc.nextLine();
        while (q-- > 0) {
            String name = sc.nextLine();
            ArrayList<Course> res = new ArrayList<>();
            for (Course x : arr) {
                if (x.lecturer.equals(name))
                    res.add(x);
            }
            Collections.sort(res);
            System.out.printf("Danh sach cho giang vien %s:\n", name);
            for (Course x : res)
                System.out.println(x);
        }
    }

}
