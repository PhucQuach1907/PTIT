import java.util.*;

class Commodity implements Comparable<Commodity> {
    private String code, name;
    private int quantity, unitPrice;

    public Commodity(String tmp, int orderNumber, String name, int quantity, int unitPrice) {
        this.code = tmp + String.format("%02d", orderNumber);
        this.name = name;
        this.quantity = quantity;
        this.unitPrice = unitPrice;
    }

    public int getPercentDiscount() {
        if (this.quantity > 10)
            return 5;
        if (this.quantity >= 8)
            return 2;
        if (this.quantity >= 5)
            return 1;
        return 0;
    }

    public int getDiscount() {
        return this.unitPrice * this.quantity * this.getPercentDiscount() / 100;
    }

    public int getCost() {
        return this.unitPrice * this.quantity - this.getDiscount();
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d", this.code, this.name, this.getDiscount(), this.getCost());
    }

    public int compareTo(Commodity other) {
        return other.getDiscount() - this.getDiscount();
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Commodity> arr = new ArrayList<>();
        HashMap<String, Integer> cnt = new HashMap<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            String name = sc.nextLine();
            int quantity = sc.nextInt(), unitPrice = sc.nextInt();
            StringBuilder tmp = new StringBuilder("");
            tmp.append(Character.toUpperCase(name.charAt(0)));
            tmp.append(Character.toUpperCase(name.charAt(name.indexOf(' ') + 1)));
            if (cnt.containsKey(tmp.toString()))
                cnt.put(tmp.toString(), cnt.get(tmp.toString()) + 1);
            else
                cnt.put(tmp.toString(), 1);
            arr.add(new Commodity(tmp.toString(), cnt.get(tmp.toString()), name, quantity, unitPrice));
        }
        Collections.sort(arr);
        for (Commodity x : arr)
            System.out.println(x);
    }
}
