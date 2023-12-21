import java.util.*;
import java.io.*;

class Product implements Comparable<Product> {
    private String code, name;
    private int soldPrice, warranty;

    public Product(String code, String name, int soldPrice, int warranty) {
        this.code = code;
        this.name = name;
        this.soldPrice = soldPrice;
        this.warranty = warranty;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d", this.code, this.name, this.soldPrice, this.warranty);
    }

    public int compareTo(Product other) {
        if (this.soldPrice != other.soldPrice)
            return other.soldPrice - this.soldPrice;
        return this.code.compareTo(other.code);
    }
}

public class App {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("SANPHAM.in"));
        int n = sc.nextInt();
        ArrayList<Product> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Product(sc.nextLine(), sc.nextLine(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(arr);
        for (Product x : arr)
            System.out.println(x);
    }
}
