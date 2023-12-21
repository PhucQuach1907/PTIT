import java.util.*;

class Staff {
    public String code, name, position;
    public int basicSalary, workdays;

    public Staff(int orderNumber, String name, String position, int basicSalary, int workdays) {
        this.code = "NV" + String.format("%02d", orderNumber);
        this.name = name;
        this.position = position;
        this.basicSalary = basicSalary;
        this.workdays = workdays;
    }

    public int getMonthlySalary() {
        return this.basicSalary * this.workdays;
    }

    public int getAllowance() {
        if (this.position.equals("GD"))
            return 500;
        if (this.position.equals("PGD"))
            return 400;
        if (this.position.equals("TP"))
            return 300;
        if (this.position.equals("KT"))
            return 250;
        return 100;
    }

    public int getAdvanced() {
        double x = (this.getMonthlySalary() + this.getAllowance()) * 2.0 / 3;
        if (x < 25000) {
            int tmp = (int) x;
            return (tmp + 500) / 1000 * 1000;
        }
        return 25000;
    }

    public int getRemain() {
        return this.getMonthlySalary() + this.getAllowance() - this.getAdvanced();
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d %d", this.code, this.name, this.getAllowance(), this.getMonthlySalary(),
                this.getAdvanced(), this.getRemain());
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Staff> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Staff(i, sc.nextLine(), sc.next(), sc.nextInt(), sc.nextInt()));
        }
        String nmc = sc.next();
        for (Staff x : arr) {
            if (x.position.equals(nmc))
                System.out.println(x);
        }
    }
}
