import java.util.*;

class Teacher {
    public String code, name;
    public int basicSalary;

    public Teacher(String code, String name, int basicSalary) {
        this.code = code;
        this.name = name;
        this.basicSalary = basicSalary;
    }

    public int getSalaryGrade() {
        return Integer.parseInt(this.code.substring(2));
    }

    public int getAllowance() {
        String tmp = this.code.substring(0, 2);
        if (tmp.equals("HT"))
            return 2000000;
        else if (tmp.equals("HP"))
            return 900000;
        return 500000;
    }

    public int getIncome() {
        return this.basicSalary * this.getSalaryGrade() + this.getAllowance();
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d", this.code, this.name, this.getSalaryGrade(), this.getAllowance(),
                this.getIncome());
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Teacher> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Teacher(sc.nextLine(), sc.nextLine(), sc.nextInt()));
        }
        int ht = 0, hp = 0;
        for (Teacher x : arr) {
            if (x.code.startsWith("HT")) {
                if (ht < 1) {
                    System.out.println(x);
                    ht++;
                }
            } else if (x.code.startsWith("HP")) {
                if (hp < 2) {
                    System.out.println(x);
                    hp++;
                }
            } else
                System.out.println(x);
        }
    }

}