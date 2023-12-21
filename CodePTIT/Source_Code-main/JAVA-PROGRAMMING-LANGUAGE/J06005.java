import java.util.*;

class Customer {
    public String name, gender, DOB, address;

    public Customer(String name, String gender, String DOB, String address) {
        this.name = name;
        this.gender = gender;
        this.DOB = DOB;
        this.address = address;
    }
}

class Commodity {
    public String name, unit;
    public int purchasePrice, soldPrice;

    public Commodity(String name, String unit, int purchasePrice, int soldPrice) {
        this.name = name;
        this.unit = unit;
        this.purchasePrice = purchasePrice;
        this.soldPrice = soldPrice;
    }
}

class Bill {
    public String code, userName, userAddress, commodityName, commodityUnit;
    public int commodityPurchasePrice, commoditySoldPrice, quantity, amount;

    public Bill(int orderNumber, String userName, String userAddress, String commodityName, String commodityUnit,
            int commodityPurchasePrice, int commoditySoldPrice, int quantity) {
        this.code = String.format("HD%03d", orderNumber);
        this.userName = userName;
        this.userAddress = userAddress;
        this.commodityName = commodityName;
        this.commodityUnit = commodityUnit;
        this.commodityPurchasePrice = commodityPurchasePrice;
        this.commoditySoldPrice = commoditySoldPrice;
        this.quantity = quantity;
        this.amount = commoditySoldPrice * quantity;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %s %d %d %d %d", code, userName, userAddress, commodityName, commodityUnit,
                commodityPurchasePrice, commoditySoldPrice, quantity, amount);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        HashMap<String, Customer> hashCustomer = new HashMap<>();
        HashMap<String, Commodity> hashCommodity = new HashMap<>();
        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 1; i <= n; i++) {
            hashCustomer.put(String.format("KH%03d", i),
                    new Customer(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            hashCommodity.put(String.format("MH%03d", i),
                    new Commodity(sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        n = sc.nextInt();
        ArrayList<Bill> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            String customerCode = sc.next(), commodityCode = sc.next();
            int quantity = sc.nextInt();
            Customer cus = hashCustomer.get(customerCode);
            Commodity com = hashCommodity.get(commodityCode);
            arr.add(new Bill(i, cus.name, cus.address, com.name, com.unit, com.purchasePrice, com.soldPrice, quantity));
        }
        for (Bill x : arr)
            System.out.println(x);
    }

}
