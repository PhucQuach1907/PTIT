import java.util.*;

class Customer {
    public String code, name;
    public int used, surcharge, total;

    public Customer(int orderNumber, String name, int oldIndex, int newIndex) {
        this.code = String.format("KH%02d", orderNumber);
        this.name = name;
        this.used = newIndex - oldIndex;
        this.surcharge = getSurcharge();
        this.total = getTotal();
    }

    public int getSurcharge() {
        if (used > 100)
            return 5;
        if (used > 50)
            return 3;
        return 2;
    }

    public int getTotal() {
        int cost = 0;
        if (used > 100) {
            int tmp = used - 100;
            cost += 200 * tmp;
            used -= tmp;
        }
        if (used > 50) {
            int tmp = used - 50;
            cost += 150 * tmp;
            used -= tmp;
        }
        if (used > 0)
            cost += 100 * used;
        return (int) Math.round(cost + cost * surcharge * 1.0 / 100);
    }

    @Override
    public String toString() {
        return String.format("%s %s %d", code, name, total);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        ArrayList<Customer> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Customer(i, sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        arr.sort((x, y) -> {
            return y.total - x.total;
        });
        for (Customer x : arr)
            System.out.println(x);
    }

}
