import java.util.*;
import java.text.*;
import java.io.*;

class Item implements Comparable<Item> {
    private String name, group;
    private int code;
    private double purchasedPrice, soldPrice, profits;

    public Item(int code, String name, String group, double purchasedPrice, double soldPrice) {
        this.code = code;
        this.name = name;
        this.group = group;
        this.purchasedPrice = purchasedPrice;
        this.soldPrice = soldPrice;
        this.profits = soldPrice - purchasedPrice;
    }

    @Override
    public String toString() {
        return String.format("%d %s %s %.2f", this.code, this.name, this.group, this.profits);
    }

    public int compareTo(Item other) {
        if (this.profits > other.profits)
            return -1;
        return 1;
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Item> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Item(i, sc.nextLine(), sc.nextLine(), sc.nextDouble(), sc.nextDouble()));
        }
        Collections.sort(arr);
        for (Item x : arr)
            System.out.println(x);
    }
}
