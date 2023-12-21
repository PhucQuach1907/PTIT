import java.util.*;
import java.io.*;

class Item {
    public String code, name, group;
    public double profit;

    public Item(int orderNumber, String name, String group, double boughtPrice, double soldPrice) {
        this.code = "MH" + String.format("%02d", orderNumber);
        this.name = name;
        this.group = group;
        this.profit = soldPrice - boughtPrice;
    }

    public String toString() {
        return String.format("%s %s %s %.2f", this.code, this.name, this.group, this.profit);
    }
}

public class App {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("MATHANG.in"));
        int n = sc.nextInt();
        ArrayList<Item> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Item(i + 1, sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        Collections.sort(arr, new Comparator<Item>() {
            @Override
            public int compare(Item a, Item b) {
                if (a.profit < b.profit)
                    return 1;
                return -1;
            }
        });
        for (Item x : arr)
            System.out.println(x);
    }
}
