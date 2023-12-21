import java.util.*;

class Student {
    public String code, name, typeOfScholarship;
    public double GPA;
    public int trainingPoint;

    public Student() {

    }

    public Student(int orderNumber, String name, double GPA, int trainingPoint) {
        this.code = String.format("SV%03d", orderNumber);
        this.name = name;
        this.GPA = GPA;
        this.trainingPoint = trainingPoint;
        this.typeOfScholarship = getTypeOfScholarship();
    }

    public String getTypeOfScholarship() {
        if (GPA >= 3.6 && trainingPoint >= 90)
            return "XUATSAC";
        if (GPA >= 3.2 && trainingPoint >= 80)
            return "GIOI";
        if (GPA >= 2.5 && trainingPoint >= 70)
            return "KHA";
        return "KHONG";
    }

    @Override
    public String toString() {
        return (name + ": " + typeOfScholarship);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt(), m = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Student(i + 1, sc.nextLine(), sc.nextDouble(), sc.nextInt()));
        }
        ArrayList<Student> sortedArr = new ArrayList<>(Collections.nCopies(n, new Student()));
        Collections.copy(sortedArr, arr);
        sortedArr.sort((x, y) -> {
            if (x.GPA > y.GPA)
                return -1;
            return 1;
        });
        double cur = 0;
        ArrayList<String> code = new ArrayList<>();
        for (Student x : sortedArr) {
            if (m > 0) {
                if (!x.typeOfScholarship.equals("KHONG")) {
                    code.add(x.code);
                    cur = x.GPA;
                    m--;
                }
            } else if (x.GPA == cur && !x.typeOfScholarship.equals("KHONG"))
                code.add(x.code);
            else
                break;
        }
        for (Student x : arr) {
            if (code.contains(x.code))
                System.out.println(x);
            else {
                x.typeOfScholarship = "KHONG";
                System.out.println(x);
            }
        }
    }

}
