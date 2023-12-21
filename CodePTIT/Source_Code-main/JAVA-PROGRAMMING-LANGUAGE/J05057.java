import java.util.*;

class Candidate {
    public String name, code;
    public double math, physic, chemistry;

    public Candidate(String code, String name, double math, double physic, double chemistry) {
        this.code = code;
        this.name = name;
        this.math = math;
        this.physic = physic;
        this.chemistry = chemistry;
    }

    public double getPriorityPoint() {
        String tmp = this.code.substring(0, 3);
        if (tmp.equals("KV1"))
            return 0.5;
        else if (tmp.equals("KV2"))
            return 1.0;
        return 2.5;
    }

    public double getFinalPoint() {
        return (this.math * 2 + this.physic + this.chemistry);
    }

    public String getPointInString(double x) {
        if (x == (int) x)
            return String.format("%d", (int) x);
        return String.format("%.1f", x);
    }

    public String getStatus() {
        return this.getFinalPoint() + this.getPriorityPoint() >= 24 ? "TRUNG TUYEN" : "TRUOT";
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %s", code, name, getPointInString(getPriorityPoint()),
                getPointInString(getFinalPoint()), getStatus());
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Candidate> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Candidate(sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
        }
        for (Candidate x : arr)
            System.out.println(x);
    }
}