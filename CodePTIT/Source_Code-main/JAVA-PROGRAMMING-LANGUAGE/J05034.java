import java.util.*;

class Student implements Comparable<Student> {
    public String code, name, className, email, company;
    public int orderNumber;

    public Student(int orderNumber, String code, String name, String className, String email, String company) {
        this.orderNumber = orderNumber;
        this.code = code;
        this.name = name;
        this.className = className;
        this.email = email;
        this.company = company;
    }

    @Override
    public String toString() {
        return String.format("%d %s %s %s %s %s", this.orderNumber, this.code, this.name, this.className, this.email,
                this.company);
    }

    public int compareTo(Student other) {
        return this.name.compareTo(other.name);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            arr.add(new Student(i, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        int q = sc.nextInt();
        sc.nextLine();
        while (q-- > 0) {
            String cpn = sc.nextLine();
            ArrayList<Student> res = new ArrayList<>();
            for (Student x : arr) {
                if (x.company.equals(cpn))
                    res.add(x);
            }
            Collections.sort(res);
            for (Student x : res)
                System.out.println(x);
        }
    }
}