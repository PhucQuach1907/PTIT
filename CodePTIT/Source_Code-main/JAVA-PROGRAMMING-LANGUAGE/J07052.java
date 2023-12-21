import java.io.*;
import java.text.*;
import java.util.*;

class Candidate implements Comparable<Candidate> {
    public String name, code;
    public double math, physic, chemistry;

    public Candidate(String code, String name, double math, double physic, double chemistry) {
        this.code = code;
        this.name = name;
        this.math = math;
        this.physic = physic;
        this.chemistry = chemistry;
    }

    public String getFormattedName() {
        ArrayList<String> tmp = new ArrayList<>(Arrays.asList(this.name.trim().toLowerCase().split("\\s+")));
        StringBuilder formattedName = new StringBuilder("");
        for (int i = 0; i < tmp.size(); i++) {
            StringBuilder w = new StringBuilder(tmp.get(i));
            w.setCharAt(0, Character.toUpperCase(w.charAt(0)));
            formattedName.append(w + " ");
        }
        return formattedName.toString().trim();
    }

    public double getPriorityPoint() {
        String tmp = this.code.substring(0, 3);
        if (tmp.equals("KV1"))
            return 0.5;
        else if (tmp.equals("KV2"))
            return 1.0;
        return 2.5;
    }

    public double getTotalPoint() {
        return (this.math * 2 + this.physic + this.chemistry + this.getPriorityPoint());
    }

    public String getStatus(double standardPoint) {
        return this.getTotalPoint() >= standardPoint ? "TRUNG TUYEN" : "TRUOT";
    }

    @Override
    public int compareTo(Candidate other) {
        if (this.getTotalPoint() != other.getTotalPoint()) {
            if (this.getTotalPoint() > other.getTotalPoint())
                return -1;
            return 1;
        }
        return this.code.compareTo(other.code);
    }
}

public class App {
    static String printPoint(double p) {
        if (p == (int) p)
            return Integer.toString((int) p);
        return String.format("%.1f", p);
    }

    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("THISINH.in"));
        int n = sc.nextInt();
        ArrayList<Candidate> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Candidate(sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
        }
        int numberOfTargets = sc.nextInt();
        Collections.sort(arr);
        double standardPoint = arr.get(numberOfTargets - 1).getTotalPoint();
        System.out.printf("%.1f\n", standardPoint);
        for (Candidate x : arr)
            System.out.printf("%s %s %s %s %s\n", x.code,
                    x.getFormattedName(), printPoint(x.getPriorityPoint()),
                    printPoint(x.getTotalPoint()), x.getStatus(standardPoint));
    }

}
