import java.util.*;

class Student implements Comparable<Student> {
    private String code, name, className;
    private double p1, p2, p3;

    public Student(String code, String name, String className, double p1, double p2, double p3) {
        this.code = code;
        this.name = name;
        this.className = className;
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %.1f %.1f %.1f", this.code, this.name, this.className, this.p1, this.p2,
                this.p3);
    }

    public int compareTo(Student other) {
        return this.code.compareTo(other.code);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble(),
                    sc.nextDouble()));
        }
        Collections.sort(arr);
        for (int i = 0; i < n; i++) {
            System.out.printf("%d ", i + 1);
            System.out.println(arr.get(i));
        }
    }
}