import java.util.*;

class Staff {
    private String code, name, position;
    private int dailySalary, workdays;

    public Staff(int orderNumber, String name, int dailySalary, int workdays, String position) {
        this.code = "NV" + String.format("%02d", orderNumber);
        this.name = name;
        this.dailySalary = dailySalary;
        this.workdays = workdays;
        this.position = position;
    }

    public int getMonthlySalary() {
        return this.dailySalary * this.workdays;
    }

    public int getBonus() {
        if (this.workdays >= 25)
            return this.getMonthlySalary() * 20 / 100;
        if (this.workdays >= 22)
            return this.getMonthlySalary() * 10 / 100;
        return 0;
    }

    public int getAllowance() {
        if (this.position.equals("GD"))
            return 250000;
        if (this.position.equals("PGD"))
            return 200000;
        if (this.position.equals("TP"))
            return 180000;
        return 150000;
    }

    public int getTotalSalary() {
        return this.getMonthlySalary() + this.getBonus() + this.getAllowance();
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d %d", this.code, this.name, this.getMonthlySalary(), this.getBonus(),
                this.getAllowance(), this.getTotalSalary());
    }

}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Staff> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Staff(i, sc.nextLine(), sc.nextInt(), sc.nextInt(), sc.next()));
        }
        int tot = 0;
        for (Staff x : arr) {
            System.out.println(x);
            tot += x.getTotalSalary();
        }
        System.out.printf("Tong chi phi tien luong: %d", tot);
    }
}
