import java.util.*;

class Commodity implements Comparable<Commodity> {
    public String code;
    public int importQuantity;

    public Commodity(String code, int importQuantity) {
        this.code = code;
        this.importQuantity = importQuantity;
    }

    public int getExportQuantity() {
        return this.code.startsWith("A") ? (int) Math.round(this.importQuantity * 0.6)
                : (int) Math.round(this.importQuantity * 0.7);
    }

    public int getUnitPrice() {
        return this.code.endsWith("Y") ? 110000 : 135000;
    }

    public int getMoney() {
        return this.getExportQuantity() * this.getUnitPrice();
    }

    public int getTax() {
        if (this.code.startsWith("A") && this.code.endsWith("Y"))
            return (int) (this.getMoney() * 0.08);
        if (this.code.startsWith("A") && this.code.endsWith("N"))
            return (int) (this.getMoney() * 0.11);
        if (this.code.startsWith("B") && this.code.endsWith("Y"))
            return (int) (this.getMoney() * 0.17);
        return (int) (this.getMoney() * 0.22);
    }

    @Override
    public String toString() {
        return String.format("%s %d %d %d %d %d", this.code, this.importQuantity, this.getExportQuantity(),
                this.getUnitPrice(), this.getMoney(), this.getTax());
    }

    public int compareTo(Commodity other) {
        return other.getTax() - this.getTax();
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Commodity> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Commodity(sc.next(), sc.nextInt()));
        String query = sc.next();
        ArrayList<Commodity> res = new ArrayList<>();
        for (Commodity x : arr) {
            if (x.code.startsWith(query))
                res.add(x);
        }
        Collections.sort(res);
        for (Commodity x : res)
            System.out.println(x);
    }
}