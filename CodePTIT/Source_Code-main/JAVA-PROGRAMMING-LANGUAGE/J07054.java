import java.io.*;
import java.text.*;
import java.util.*;

class Student implements Comparable<Student> {
    public String code, name;
    public int oop, cpp, bi2;

    public Student(int orderNumber, String name, int oop, int cpp, int bi2) {
        this.code = "SV" + String.format("%02d", orderNumber);
        this.name = name;
        this.oop = oop;
        this.cpp = cpp;
        this.bi2 = bi2;
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

    public double getAveragePoint() {
        return (this.oop * 3 + this.cpp * 3 + this.bi2 * 2) * 1.0 / 8;
    }

    @Override
    public int compareTo(Student other) {
        if (this.getAveragePoint() != other.getAveragePoint()) {
            if (this.getAveragePoint() > other.getAveragePoint())
                return -1;
            return 1;
        }
        return this.code.compareTo(other.code);
    }
}

public class App {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("BANGDIEM.in"));
        int n = sc.nextInt();
        ArrayList<Student> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Student(i + 1, sc.nextLine(), sc.nextInt(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(arr);
        double curPoint = -1;
        int curRank = 0;
        for (int i = 0; i < n; i++) {
            System.out.printf("%s %s %.2f ", arr.get(i).code, arr.get(i).getFormattedName(),
                    arr.get(i).getAveragePoint());
            if (arr.get(i).getAveragePoint() != curPoint) {
                System.out.printf("%d\n", i + 1);
                curPoint = arr.get(i).getAveragePoint();
                curRank = i + 1;
            } else
                System.out.printf("%d\n", curRank);
        }
    }

}
