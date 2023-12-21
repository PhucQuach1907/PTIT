import java.util.*;

class Student {
    public String code, name;
    public double averagePoint;
    public int rank;

    public Student(int orderNumber, String name, double averagePoint) {
        this.code = String.format("HS%02d", orderNumber);
        this.name = name;
        this.averagePoint = averagePoint;
    }

    public String getClassification() {
        if (this.averagePoint >= 9)
            return "Gioi";
        if (this.averagePoint >= 7)
            return "Kha";
        if (this.averagePoint >= 5)
            return "Trung Binh";
        return "Yeu";
    }

    public void setRank(int rank) {
        this.rank = rank;
    }

    @Override
    public String toString() {
        return String.format("%s %s %.1f %s %d", this.code, this.name, this.averagePoint, this.getClassification(),
                this.rank);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Student(i, sc.nextLine(), sc.nextDouble()));
        }
        arr.sort((x, y) -> {
            if (x.averagePoint > y.averagePoint)
                return -1;
            return 1;
        });
        for (int i = 0; i < n; i++)
            arr.get(i).setRank(i + 1);
        for (int i = 1; i < n; i++) {
            if (arr.get(i).averagePoint == arr.get(i - 1).averagePoint)
                arr.get(i).setRank(arr.get(i - 1).rank);
        }
        arr.sort((x, y) -> {
            return x.code.compareTo(y.code);
        });
        for (Student x : arr)
            System.out.println(x);
    }
}
