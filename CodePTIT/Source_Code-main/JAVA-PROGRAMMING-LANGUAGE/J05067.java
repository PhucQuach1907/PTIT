import java.util.*;

class Fuel {
    public String code, manufacturer;
    public long quantity, unitPrice, tax, amount;

    public Fuel(String code, long quantity) {
        this.code = code;
        this.quantity = quantity;
        this.manufacturer = getManufacturer();
        this.unitPrice = getUnitPrice();
        this.tax = getTax();
        this.amount = getAmount();
    }

    public String getManufacturer() {
        if (code.endsWith("BP"))
            return "British Petro";
        if (code.endsWith("ES"))
            return "Esso";
        if (code.endsWith("SH"))
            return "Shell";
        if (code.endsWith("CA"))
            return "Castrol";
        if (code.endsWith("MO"))
            return "Mobil";
        return "Trong Nuoc";
    }

    public long getUnitPrice() {
        if (code.charAt(0) == 'X')
            return 128000;
        if (code.charAt(0) == 'D')
            return 11200;
        return 9700;
    }

    public long getTax() {
        if (code.endsWith("TN"))
            return 0;
        if (code.charAt(0) == 'X')
            return (long) (unitPrice * quantity * 0.03);
        if (code.charAt(0) == 'D')
            return (long) (unitPrice * quantity * 0.035);
        return (long) (unitPrice * quantity * 0.02);
    }

    public long getAmount() {
        return (unitPrice * quantity + tax);
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d %d", code, manufacturer, unitPrice, tax, amount);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Fuel> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Fuel(sc.next(), sc.nextLong()));
        for (Fuel x : arr)
            System.out.println(x);
    }

}