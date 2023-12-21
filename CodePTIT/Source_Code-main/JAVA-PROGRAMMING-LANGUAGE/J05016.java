import java.text.*;
import java.util.*;
import java.util.concurrent.TimeUnit;

class Customer implements Comparable<Customer> {
    private String code, name, roomNumber, arrival, left;
    private int service;

    public Customer(int orderNumber, String name, String roomNumber, String arrival, String left, int service) {
        this.code = "KH" + String.format("%02d", orderNumber);
        this.name = name;
        this.roomNumber = roomNumber;
        this.arrival = arrival;
        this.left = left;
        this.service = service;
    }

    public int getNumberOfDaysStayed() throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy", Locale.ENGLISH);
        Date firstDate = sdf.parse(this.arrival);
        Date secondDate = sdf.parse(this.left);
        long diffInMillies = Math.abs(secondDate.getTime() - firstDate.getTime());
        return (int) TimeUnit.DAYS.convert(diffInMillies, TimeUnit.MILLISECONDS) + 1;
    }

    public int getUnitPrice() {
        char floor = this.roomNumber.charAt(0);
        if (floor == '1')
            return 25;
        if (floor == '2')
            return 34;
        if (floor == '3')
            return 50;
        return 80;
    }

    public int getTotalCost() throws ParseException {
        return this.getUnitPrice() * this.getNumberOfDaysStayed() + this.service;
    }

    @Override
    public int compareTo(Customer other) {
        try {
            if (other.getTotalCost() > this.getTotalCost())
                return 1;
            else
                return -1;
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return 0;
    }

    public String toString() {
        try {
            return String.format("%s %s %s %d %d", this.code, this.name, this.roomNumber,
                    this.getNumberOfDaysStayed(), this.getTotalCost());
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return "";
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws ParseException {

        int n = sc.nextInt();
        ArrayList<Customer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new Customer(i + 1, sc.nextLine().trim(), sc.nextLine().trim(), sc.nextLine().trim(),
                    sc.nextLine().trim(), sc.nextInt()));
        }
        Collections.sort(arr);
        for (Customer x : arr)
            System.out.println(x);
    }

}
