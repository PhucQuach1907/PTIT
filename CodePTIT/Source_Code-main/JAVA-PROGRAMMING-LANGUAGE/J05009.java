import java.util.*;
import java.text.*;
import java.io.*;

class Candidate implements Comparable<Candidate> {
    private String name, DOB;
    private double p1, p2, p3;
    private int code;

    public Candidate(int code, String name, String DOB, double p1, double p2, double p3) {
        this.code = code;
        this.name = name;
        this.DOB = DOB;
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
    }

    public double getTotalPoint() {
        return this.p1 + this.p2 + this.p3;
    }

    @Override
    public String toString() {
        return String.format("%d %s %s %.1f", this.code, this.name, this.DOB, this.getTotalPoint());
    }

    public int compareTo(Candidate other) {
        return this.code - other.code;
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Candidate> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Candidate(i, sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
        }
        double maxPoint = 0;
        for (Candidate x : arr)
            maxPoint = Math.max(maxPoint, x.getTotalPoint());
        ArrayList<Candidate> res = new ArrayList<>();
        for (Candidate x : arr) {
            if (x.getTotalPoint() == maxPoint)
                res.add(x);
        }
        Collections.sort(res);
        for (Candidate x : res)
            System.out.println(x);
    }
}
