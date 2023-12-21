import java.util.*;
import static java.lang.Math.*;

class Candidate {
    private String name;
    private String DOB;
    private double mark1, mark2, mark3;

    public Candidate(String name, String DOB, double mark1, double mark2, double mark3) {
        this.name = name;
        this.DOB = DOB;
        this.mark1 = mark1;
        this.mark2 = mark2;
        this.mark3 = mark3;
    }

    public double Sum() {
        return this.mark1 + this.mark2 + this.mark3;
    }

    @Override
    public String toString() {
        return String.format("%s %s %.1f", this.name, this.DOB, this.Sum());
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String name = sc.nextLine();
        String DOB = sc.next();
        double mark1 = sc.nextDouble(), mark2 = sc.nextDouble(), mark3 = sc.nextDouble();
        Candidate cd = new Candidate(name, DOB, mark1, mark2, mark3);
        System.out.println(cd);
    }
}
