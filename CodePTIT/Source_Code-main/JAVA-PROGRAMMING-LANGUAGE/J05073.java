import java.util.*;

class Commodity {
    public String code;
    public int quantity, unitPrice, baseCost;
    public double tax, transportFee, totalCost, profit;

    public Commodity(String code, int unitPrice, int quantity) {
        this.code = code;
        this.unitPrice = unitPrice;
        this.quantity = quantity;
        this.baseCost = unitPrice * quantity;
        this.tax = getTax();
        this.transportFee = getTransportFee();
        this.totalCost = getTotalCost();
        this.profit = getProfit();
    }

    public double getTax() {
        double res;
        char c = code.charAt(0);
        if (c == 'T')
            res = baseCost * 0.29;
        else if (c == 'C')
            res = baseCost * 0.1;
        else if (c == 'D')
            res = baseCost * 0.08;
        else
            res = baseCost * 0.02;
        if (code.charAt(code.length() - 1) == 'C')
            return (res - res * 0.05);
        return res;
    }

    public double getTransportFee() {
        char c = code.charAt(0);
        if (c == 'T')
            return baseCost * 0.04;
        else if (c == 'C')
            return baseCost * 0.03;
        else if (c == 'D')
            return baseCost * 0.025;
        return baseCost * 0.005;
    }

    public double getTotalCost() {
        return baseCost * 1.0 + tax + transportFee;
    }

    public double getProfit() {
        return (totalCost + totalCost * 0.2) / quantity;
    }

    @Override
    public String toString() {
        return String.format("%s %.2f", code, profit);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        ArrayList<Commodity> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Commodity(sc.next(), sc.nextInt(), sc.nextInt()));
        for (Commodity x : arr)
            System.out.println(x);
    }

}
