import java.util.*;

class Clothes implements Comparable<Clothes> {
    private String name, code;
    private int unitPrice, quantity;

    public Clothes(String name, String code, int unitPrice, int quantity) {
        this.name = name;
        this.code = code;
        this.unitPrice = unitPrice;
        this.quantity = quantity;
    }

    public String getOrderNumber() {
        return this.code.substring(1, 4);
    }

    public int getCost() {
        return this.unitPrice * this.quantity;
    }

    public int getSale() {
        return (int) (this.code.endsWith("1") ? 0.5 * this.getCost() : 0.3 * this.getCost());
    }

    public int getAmount() {
        return this.getCost() - this.getSale();
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %d %d", this.name, this.code, this.getOrderNumber(), this.getSale(),
                this.getAmount());
    }

    public int compareTo(Clothes other) {
        return this.getOrderNumber().compareTo(other.getOrderNumber());
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Clothes> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Clothes(sc.nextLine(), sc.next(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(arr);
        for (Clothes x : arr)
            System.out.println(x);
    }
}
