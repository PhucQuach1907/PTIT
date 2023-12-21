import java.util.*;

class Student {
    public String code, name, phoneNumber;
    public int group;

    public Student(String code, String name, String phoneNumber, String group) {
        this.code = code;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.group = Integer.parseInt(group);
    }

    @Override
    public String toString() {
        return String.format("%s %s %s", code, name, phoneNumber);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            arr.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        ArrayList<String> task = new ArrayList<>();
        for (int i = 0; i < m; i++)
            task.add(sc.nextLine());
        int q = sc.nextInt();
        while (q-- > 0) {
            int gr = sc.nextInt();
            ArrayList<Student> res = new ArrayList<>();
            for (Student x : arr) {
                if (x.group == gr)
                    res.add(x);
            }
            System.out.printf("DANH SACH NHOM %d:\n", gr);
            for (Student x : res)
                System.out.println(x);
            System.out.printf("Bai tap dang ky: %s\n", task.get(gr - 1));
        }
    }

}