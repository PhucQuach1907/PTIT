import java.util.*;

class Student {
    public String code, name, phoneNumber, task;
    public int group;

    public Student(String code, String name, String phoneNumber, String group) {
        this.code = code;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.group = Integer.parseInt(group);
    }

    public void setTask(String task) {
        this.task = task;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %d %s", code, name, phoneNumber, group, task);
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
        for (Student x : arr)
            x.setTask(task.get(x.group - 1));
        arr.sort((x, y) -> {
            return x.code.compareTo(y.code);
        });
        for (Student x : arr)
            System.out.println(x);
    }

}