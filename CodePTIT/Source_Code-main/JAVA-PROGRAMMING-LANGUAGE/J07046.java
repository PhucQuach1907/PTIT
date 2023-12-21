import java.util.*;
import java.util.concurrent.TimeUnit;
import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;

class Customer implements Comparable<Customer> {
    public String code, name, roomCode;
    public long stayDays;

    public Customer(int orderNumber, String name, String roomCode, String arrivalTime, String leftTime)
            throws ParseException {
        this.code = "KH" + String.format("%02d", orderNumber);
        this.name = name;
        this.roomCode = roomCode;
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy", Locale.ENGLISH);
        Date firstDate = sdf.parse(arrivalTime);
        Date secondDate = sdf.parse(leftTime);
        long diffInMillies = Math.abs(secondDate.getTime() - firstDate.getTime());
        this.stayDays = TimeUnit.DAYS.convert(diffInMillies, TimeUnit.MILLISECONDS);
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %d", this.code, this.name, this.roomCode, this.stayDays);
    }

    public int compareTo(Customer other) {
        return (int) (other.stayDays - this.stayDays);
    }
}

public class App {

    public static void main(String[] args) throws IOException, ParseException {
        Scanner sc = new Scanner(new File("KHACH.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Customer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Customer(i + 1, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        Collections.sort(arr);
        for (Customer x : arr)
            System.out.println(x);
    }
}
