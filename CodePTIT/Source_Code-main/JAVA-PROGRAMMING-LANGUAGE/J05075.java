import java.util.*;

class Student {
    public String code, name, className, note;
    public int point;

    public Student(String code, String name, String className) {
        this.code = code;
        this.name = name;
        this.className = className;
    }

    public void setPoint(int point) {
        this.point = point;
    }

    @Override
    public String toString() {
        if (point == 0)
            return String.format("%s %s %s %d KDDK", code, name, className, point);
        return String.format("%s %s %s %d", code, name, className, point);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Student(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        HashMap<String, Integer> myMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String code = sc.next();
            String attendance = sc.next();
            int point = 10;
            for (int j = 0; j < attendance.length(); j++) {
                if (attendance.charAt(j) == 'v')
                    point -= 2;
                else if (attendance.charAt(j) == 'm')
                    point -= 1;
            }
            point = Math.max(0, point);
            myMap.put(code, point);
        }
        for (Student x : arr)
            x.setPoint(myMap.get(x.code));
        String nmc = sc.next();
        for (Student x : arr) {
            if (x.className.equals(nmc))
                System.out.println(x);
        }
    }

}