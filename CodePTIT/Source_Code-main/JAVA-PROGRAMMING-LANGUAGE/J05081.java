import java.util.*;
import java.io.*;

class Item {
    public String code, name, unit;
    public int boughtPrice, soldPrice, profit;

    public Item(int orderNumber, String name, String unit, int boughtPrice, int soldPrice) {
        this.code = "MH" + String.format("%03d", orderNumber);
        this.name = name;
        this.unit = unit;
        this.boughtPrice = boughtPrice;
        this.soldPrice = soldPrice;
        this.profit = soldPrice - boughtPrice;
    }

    public String toString() {
        return String.format("%s %s %s %d %d %d", this.code, this.name, this.unit, this.boughtPrice, this.soldPrice,
                this.profit);
    }
}

public class App {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Item> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Item(i + 1, sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(arr, new Comparator<Item>() {
            @Override
            public int compare(Item a, Item b) {
                if (a.profit != b.profit)
                    return b.profit - a.profit;
                return a.code.compareTo(b.code);
            }
        });
        for (Item x : arr)
            System.out.println(x);
    }
}
