import java.util.*;

class Lecturer {
    public String code, name, admissionCode, status, specializedMajorName;
    public double itPoint, specializedMajorPoint, priorityPoint, totalPoint;

    public Lecturer(int orderNumber, String name, String admissionCode, double itPoint, double specializedMajorPoint) {
        this.code = String.format("GV%02d", orderNumber);
        this.name = name;
        this.admissionCode = admissionCode;
        this.itPoint = itPoint;
        this.specializedMajorPoint = specializedMajorPoint;
        this.specializedMajorName = getSpecializedMajorName();
        this.priorityPoint = getPriorityPoint();
        this.totalPoint = getTotalPoint();
        this.status = getStatus();
    }

    public String getSpecializedMajorName() {
        char c = admissionCode.charAt(0);
        if (c == 'A')
            return "TOAN";
        if (c == 'B')
            return "LY";
        return "HOA";
    }

    public double getPriorityPoint() {
        char c = admissionCode.charAt(1);
        if (c == '1')
            return 2.0;
        if (c == '2')
            return 1.5;
        if (c == '3')
            return 1.0;
        return 0;
    }

    public double getTotalPoint() {
        return itPoint * 2 + specializedMajorPoint + priorityPoint;
    }

    public String getStatus() {
        if (totalPoint >= 18)
            return "TRUNG TUYEN";
        return "LOAI";
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %.1f %s", code, name, specializedMajorName, totalPoint, status);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Lecturer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Lecturer(i + 1, sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        arr.sort((x, y) -> {
            if (x.totalPoint != y.totalPoint) {
                if (x.totalPoint < y.totalPoint)
                    return 1;
                return -1;
            }
            return x.code.compareTo(y.code);
        });
        for (Lecturer x : arr)
            System.out.println(x);
    }
}
