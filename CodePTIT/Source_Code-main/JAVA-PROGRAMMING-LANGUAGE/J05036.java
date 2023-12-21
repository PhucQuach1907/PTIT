import java.util.*;

class Commodity {
    public String code, name, unit;
    public int unitPrice, quantity;

    public Commodity(int orderNumber, String name, String unit, int unitPrice, int quantity) {
        this.code = "MH" + String.format("%02d", orderNumber);
        this.name = name;
        this.unit = unit;
        this.unitPrice = unitPrice;
        this.quantity = quantity;
    }

    public int getTransportFee() {
        return (int) Math.round(this.unitPrice * this.quantity * 0.05);
    }

    public int getTotal() {
        return (int) Math.round(this.unitPrice * this.quantity + this.getTransportFee());
    }

    public int getSoldPrice() {
        return (int) Math.round(1.02 * this.getTotal());
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %d %d %d", this.code, this.name, this.unit, this.getTransportFee(),
                this.getTotal(), this.getSoldPrice());
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Commodity> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Commodity(i, sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        for (Commodity x : arr)
            System.out.println(x);
    }
}