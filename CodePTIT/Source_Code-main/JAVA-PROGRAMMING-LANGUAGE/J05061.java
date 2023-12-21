import java.io.*;
import java.text.*;
import java.util.*;

class Candidate {
    public String name, code, DOB;
    public double theoryPoint, practicePoint;

    public Candidate(int orderNumber, String name, String DOB, double theoryPoint, double practicePoint) {
        this.code = "PH" + String.format("%02d", orderNumber);
        this.name = name;
        this.DOB = DOB;
        this.theoryPoint = theoryPoint;
        this.practicePoint = practicePoint;
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

    public int getAge() {
        return 2021 - Integer.parseInt(this.DOB.substring(this.DOB.lastIndexOf("/") + 1));
    }

    public double getRewardPoint() {
        if (this.theoryPoint >= 8 && this.practicePoint >= 8)
            return 1.0;
        if (this.theoryPoint >= 7.5 && this.practicePoint >= 7.5)
            return 0.5;
        return 0.0;
    }

    public int getTotalPoint() {
        return Math.min(10,
                (int) Math.round((this.theoryPoint + this.practicePoint) * 1.0 / 2 + this.getRewardPoint()));
    }

    public String getClassification() {
        int mark = this.getTotalPoint();
        if (mark == 9 || mark == 10)
            return "Xuat sac";
        if (mark == 8)
            return "Gioi";
        if (mark == 7)
            return "Kha";
        if (mark == 5 || mark == 6)
            return "Trung binh";
        return "Truot";
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %s", this.code, this.getFormattedName(), this.getAge(), this.getTotalPoint(),
                this.getClassification());
    }
}

public class App {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Candidate> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Candidate(i + 1, sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        arr.sort((x, y) -> {
            if (x.getTotalPoint() != y.getTotalPoint())
                return y.getTotalPoint() - x.getTotalPoint();
            return x.code.compareTo(y.code);
        });
        for (Candidate x : arr)
            System.out.println(x);
    }

}