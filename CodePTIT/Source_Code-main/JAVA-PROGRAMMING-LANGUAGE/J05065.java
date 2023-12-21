import java.util.*;

class Staff {
    public String code, name, position, gradeSalary;

    public Staff(String code, String name, String position, String gradeSalary) {
        this.name = name;
        this.code = code;
        this.position = position;
        this.gradeSalary = gradeSalary;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", name, position, code, gradeSalary);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        ArrayList<Staff> arr = new ArrayList<>();
        int gd = 0, tp = 0, pp = 0;
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            String name = sc.nextLine();
            String position = s.substring(0, 2);
            String gradeSalary = s.substring(2, 4);
            String code = s.substring(4);
            if (position.equals("GD") && gd < 1) {
                arr.add(new Staff(code, name, position, gradeSalary));
                gd++;
            } else if (position.equals("TP") && tp < 3) {
                arr.add(new Staff(code, name, position, gradeSalary));
                tp++;
            } else if (position.equals("PP") && pp < 3) {
                arr.add(new Staff(code, name, position, gradeSalary));
                pp++;
            } else
                arr.add(new Staff(code, name, "NV", gradeSalary));
        }
        int q = sc.nextInt();
        while (q-- > 0) {
            String positionQuery = sc.next();
            ArrayList<Staff> res = new ArrayList<>();
            for (Staff x : arr) {
                if (x.position.equals(positionQuery))
                    res.add(x);
            }
            res.sort((x, y) -> {
                if (!x.gradeSalary.equals(y.gradeSalary))
                    return y.gradeSalary.compareTo(x.gradeSalary);
                return x.code.compareTo(y.code);
            });
            for (Staff x : res)
                System.out.println(x);
            System.out.println();
        }
    }

}
