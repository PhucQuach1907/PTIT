import java.util.*;

class Student implements Comparable<Student> {
    private String code, name;
    public ArrayList<Double> pointList;

    public Student(int orderNumber, String name, ArrayList<Double> pointList) {
        this.code = "HS" + String.format("%02d", orderNumber);
        this.name = name;
        this.pointList = new ArrayList<>(Collections.nCopies(10, 0.0));
        Collections.copy(this.pointList, pointList);
    }

    public double getAveragePoint() {
        double sum = (this.pointList.get(0) + this.pointList.get(1)) * 2;
        for (int i = 2; i < 10; i++)
            sum += this.pointList.get(i);
        int tmp = (int) Math.round(sum / 12 * 10);
        return (double) tmp / 10;
    }

    public String getClassification() {
        double x = this.getAveragePoint();
        if (x >= 9)
            return "XUAT SAC";
        if (x >= 8)
            return "GIOI";
        if (x >= 7)
            return "KHA";
        if (x >= 5)
            return "TB";
        return "YEU";
    }

    @Override
    public String toString() {
        return String.format("%s %s %.1f %s", this.code, this.name, this.getAveragePoint(), this.getClassification());
    }

    public int compareTo(Student other) {
        if (this.getAveragePoint() != other.getAveragePoint()) {
            if (this.getAveragePoint() > other.getAveragePoint())
                return -1;
            return 1;
        }
        return this.code.compareTo(other.code);
    }

}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            String name = sc.nextLine();
            ArrayList<Double> tmp = new ArrayList<>();
            for (int j = 0; j < 10; j++)
                tmp.add(sc.nextDouble());
            arr.add(new Student(i + 1, name, tmp));
        }
        Collections.sort(arr);
        for (Student x : arr)
            System.out.println(x);
    }
}
