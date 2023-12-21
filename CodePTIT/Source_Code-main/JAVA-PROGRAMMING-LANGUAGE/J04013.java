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

    public String getStatus() {
        return this.getFinalPoint() + this.getPriorityPoint() >= 24 ? "TRUNG TUYEN" : "TRUOT";
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String code = sc.nextLine(), name = sc.nextLine();
        double math = sc.nextDouble(), physic = sc.nextDouble(), chemistry = sc.nextDouble();
        Candidate nmc = new Candidate(code, name, math, physic, chemistry);
        System.out.printf("%s %s ", nmc.code, nmc.name);
        if (nmc.getPriorityPoint() == (int) nmc.getPriorityPoint())
            System.out.printf("%d ", (int) nmc.getPriorityPoint());
        else
            System.out.printf("%.1f ", nmc.getPriorityPoint());
        if (nmc.getFinalPoint() == (int) nmc.getFinalPoint())
            System.out.printf("%d ", (int) nmc.getFinalPoint());
        else
            System.out.printf("%.1f ", nmc.getFinalPoint());
        System.out.printf("%s", nmc.getStatus());
    }
}