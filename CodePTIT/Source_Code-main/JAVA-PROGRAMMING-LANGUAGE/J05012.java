import java.util.*;

class Commodity {
    public String code, name;
    public long quantity, unitPrice, discount, total;

    public Commodity(String code, String name, long quantity, long unitPrice, long discount) {
        this.code = code;
        this.name = name;
        this.quantity = quantity;
        this.unitPrice = unitPrice;
        this.discount = discount;
        this.total = quantity * unitPrice - discount;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d %d", code, name, quantity, unitPrice, discount, total);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Commodity> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Commodity(sc.nextLine(), sc.nextLine(), sc.nextLong(), sc.nextLong(), sc.nextLong()));
        }
        arr.sort((x, y) -> {
            if (x.total < y.total)
                return 1;
            return -1;
        });
        for (Commodity x : arr)
            System.out.println(x);
    }
}
