import java.util.*;

class Student implements Comparable<Student> {
    private String name;
    private int accepted, submit;

    public Student(String name, int accepted, int submit) {
        this.name = name;
        this.accepted = accepted;
        this.submit = submit;
    }

    @Override
    public String toString() {
        return String.format("%s %d %d", this.name, this.accepted, this.submit);
    }

    public int compareTo(Student other) {
        if (this.accepted != other.accepted)
            return other.accepted - this.accepted;
        if (this.submit != other.submit)
            return this.submit - other.submit;
        return this.name.compareTo(other.name);
    }

}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Student(sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(arr);
        for (Student x : arr)
            System.out.println(x);
    }
}
