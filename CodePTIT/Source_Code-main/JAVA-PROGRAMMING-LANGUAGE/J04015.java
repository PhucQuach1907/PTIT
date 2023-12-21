import java.util.*;

class Teacher {
    private String code, name;
    private int basicSalary;

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
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String code = sc.nextLine();
        String name = sc.nextLine();
        int basicSalary = sc.nextInt();
        Teacher person = new Teacher(code, name, basicSalary);
        System.out.println(person);
    }
}