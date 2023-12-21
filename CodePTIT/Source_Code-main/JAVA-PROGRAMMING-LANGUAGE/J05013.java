import java.util.*;

class Candidate {
    public String code, name, status;
    public double theory, practice, average;

    public Candidate(int orderNumber, String name, double theory, double practice) {
        this.code = String.format("TS%02d", orderNumber);
        this.name = name;
        this.theory = getTheoryPoint(theory);
        this.practice = getPracticePoint(practice);
        this.average = getAveragePoint();
        this.status = getStatus();
    }

    public double getTheoryPoint(double theory) {
        if (theory <= 10)
            return theory;
        int tmp = (int) theory;
        double p = (tmp / 10) + (tmp % 10) * 1.0 / 10;
        return p;
    }

    public double getPracticePoint(double practice) {
        if (practice <= 10)
            return practice;
        int tmp = (int) practice;
        double p = (tmp / 10) + (tmp % 10) * 1.0 / 10;
        return p;
    }

    public double getAveragePoint() {
        return (this.theory + this.practice) * 1.0 / 2;
    }

    public String getStatus() {
        if (average > 9.5)
            return "XUAT SAC";
        if (average >= 8)
            return "DAT";
        if (average >= 5)
            return "CAN NHAC";
        return "TRUOT";
    }

    @Override
    public String toString() {
        return String.format("%s %s %.2f %s", code, name, average, status);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Candidate> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Candidate(i + 1, sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        arr.sort((x, y) -> {
            if (x.average < y.average)
                return 1;
            return -1;
        });
        for (Candidate x : arr)
            System.out.println(x);
    }
}
