import java.io.*;
import java.text.*;
import java.util.*;

class Candidate implements Comparable<Candidate> {
    public String code, name, ethnicName;
    public int regionNumber;
    public double point;

    public Candidate(int orderNumber, String name, String point, String ethnicName, int regionNumber) {
        this.code = "TS" + String.format("%02d", orderNumber);
        this.name = name;
        this.point = Double.parseDouble(point);
        this.ethnicName = ethnicName;
        this.regionNumber = regionNumber;
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

    public double getPriorityPointByEthnicity() {
        if (this.ethnicName.equals("Kinh"))
            return 0;
        return 1.5;
    }

    public double getPriorityPointByRegion() {
        if (this.regionNumber == 1)
            return 1.5;
        if (this.regionNumber == 2)
            return 1;
        return 0;
    }

    public double getTotalPoint() {
        return this.point + this.getPriorityPointByEthnicity() + this.getPriorityPointByRegion();
    }

    public String getStatus() {
        return (this.getTotalPoint() >= 20.5 ? "Do" : "Truot");
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

    public String toString() {
        return String.format("%s %s %.1f %s", this.code, this.getFormattedName(), this.getTotalPoint(),
                this.getStatus());
    }
}

public class App {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("THISINH.in"));
        int n = sc.nextInt();
        ArrayList<Candidate> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Candidate(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextInt()));
        }
        Collections.sort(arr);
        for (Candidate x : arr)
            System.out.println(x);
    }

}
