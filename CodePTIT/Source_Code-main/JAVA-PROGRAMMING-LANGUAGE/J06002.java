import java.util.*;

class Order {
    public String code, name;
    public long sales, totalCost;

    public Order(String billCode, int orderNumber, String name, long unitPrice, long quanity) {
        this.code = String.format("%s-%03d", billCode, orderNumber);
        this.name = name;
        this.sales = getSales(quanity, unitPrice);
        this.totalCost = getTotalCost(quanity, unitPrice);
    }

    public long getSales(long quantity, long unitPrice) {
        long cost = quantity * unitPrice;
        if (quantity >= 150)
            return cost * 50 / 100;
        if (quantity >= 100)
            return cost * 30 / 100;
        if (quantity >= 50)
            return cost * 15 / 100;
        return 0;
    }

    public long getTotalCost(long quantity, long unitPrice) {
        return (quantity * unitPrice - sales);
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d", code, name, sales, totalCost);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int m = sc.nextInt();
        sc.nextLine();
        HashMap<String, ArrayList<String>> info = new HashMap<>();
        for (int i = 0; i < m; i++) {
            String code = sc.nextLine(), name = sc.nextLine(), price1 = sc.nextLine(), price2 = sc.nextLine();
            info.put(code, new ArrayList<>());
            info.get(code).add(name);
            info.get(code).add(price1);
            info.get(code).add(price2);
        }
        int n = sc.nextInt();
        ArrayList<Order> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String billCode = sc.next();
            long quanity = sc.nextLong();
            String name = info.get(billCode.substring(0, 2)).get(0);
            long unitPrice = Long.parseLong(info.get(billCode.substring(0, 2)).get(billCode.charAt(2) - '0'));
            arr.add(new Order(billCode, i + 1, name, unitPrice, quanity));
        }
        arr.sort((x, y) -> {
            if (x.totalCost > y.totalCost)
                return -1;
            return 1;
        });
        for (Order x : arr)
            System.out.println(x);
    }

}
