import java.util.*;

class Customer {
    private String code, type;
    private long first, last;

    public Customer(int orderNumber, String type, long first, long last) {
        this.code = "KH" + String.format("%02d", orderNumber);
        this.type = type;
        this.first = first;
        this.last = last;
    }

    public long getCoefficient() {
        if (this.type.equals("KD"))
            return 3;
        if (this.type.equals("NN"))
            return 5;
        if (this.type.equals("TT"))
            return 4;
        return 2;
    }

    public long getAmount() {
        return (last - first) * this.getCoefficient() * 550;
    }

    public long getPhuTroi() {
        long used = last - first;
        if (used < 50)
            return 0;
        if (used > 100)
            return this.getAmount();
        long tmp = Math.round(this.getAmount() * 35 * 1.0 / 100);
        return tmp;
    }

    public long getTotalCost() {
        return this.getPhuTroi() + this.getAmount();
    }

    @Override
    public String toString() {
        return String.format("%s %d %d %d %d", this.code, this.getCoefficient(), this.getAmount(), this.getPhuTroi(),
                this.getTotalCost());
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Customer> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            arr.add(new Customer(i, sc.next(), sc.nextLong(), sc.nextLong()));
        for (Customer x : arr)
            System.out.println(x);
    }
}
