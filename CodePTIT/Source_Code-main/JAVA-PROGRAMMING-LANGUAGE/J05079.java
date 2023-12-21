import java.util.*;

class Course implements Comparable<Course> {
    public String name, group, lecturer;

    public Course(String name, String group, String lecturer) {
        this.name = name;
        this.group = group;
        this.lecturer = lecturer;
    }

    @Override
    public int compareTo(Course other) {
        return this.group.compareTo(other.group);
    }

    public String toString() {
        return group + " " + lecturer;
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, ArrayList<Course>> myMap = new HashMap<>();
        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            String code = sc.nextLine();
            if (!myMap.containsKey(code))
                myMap.put(code, new ArrayList<>());
            myMap.get(code).add(new Course(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        myMap.forEach((key, value) -> {
            Collections.sort(value);
        });
        int q = sc.nextInt();
        while (q-- > 0) {
            String code = sc.next();
            System.out.printf("Danh sach nhom lop mon %s:\n", myMap.get(code).get(0).name);
            for (Course x : myMap.get(code))
                System.out.println(x);
        }
    }

}
