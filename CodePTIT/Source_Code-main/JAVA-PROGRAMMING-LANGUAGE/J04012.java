import java.util.*;

class Staff {
    private String name, code, position;
    private int basicSalary, dayWorking;

    public Staff(String name, int basicSalary, int dayWorking, String position) {
        this.name = name;
        this.basicSalary = basicSalary;
        this.dayWorking = dayWorking;
        this.position = position;
        this.code = "NV01";
    }

    public int getSalaryOfMonth() {
        return this.basicSalary * this.dayWorking;
    }

    public int getBonus() {
        if (this.dayWorking >= 25)
            return (20 * this.getSalaryOfMonth()) / 100;
        else if (this.dayWorking >= 22)
            return (10 * this.getSalaryOfMonth()) / 100;
        return 0;
    }

    public int getAllowance() {
        if (this.position.equals("GD"))
            return 250000;
        else if (this.position.equals("PGD"))
            return 200000;
        else if (this.position.equals("TP"))
            return 180000;
        return 150000;
    }

    public int getIncome() {
        return this.getSalaryOfMonth() + this.getBonus() + this.getAllowance();
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d %d", this.code, this.name, this.getSalaryOfMonth(), this.getBonus(),
                this.getAllowance(), this.getIncome());
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String name = sc.nextLine();
        int basicSalary = sc.nextInt();
        int dayWorking = sc.nextInt();
        String position = sc.next();
        Staff person = new Staff(name, basicSalary, dayWorking, position);
        System.out.println(person);
    }
}