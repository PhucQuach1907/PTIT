import java.util.*;
import java.text.*;
import java.io.*;

class Staff implements Comparable<Staff> {
    private String code, name, gender, DOB, address, phoneNumber, dateContractor;

    public Staff(int orderNumber, String name, String gender, String DOB, String address, String phoneNumber,
            String dateContractor) {
        this.code = String.format("%05d", orderNumber);
        this.name = name;
        this.gender = gender;
        this.DOB = DOB;
        this.address = address;
        this.phoneNumber = phoneNumber;
        this.dateContractor = dateContractor;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %s %s %s", this.code, this.name, this.gender, this.DOB, this.address,
                this.phoneNumber, this.dateContractor);
    }

    public int compareTo(Staff other) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy", Locale.ENGLISH);
        Date d1, d2;
        try {
            d1 = sdf.parse(this.DOB);
            d2 = sdf.parse(other.DOB);
            return d1.compareTo(d2);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return 0;
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Staff> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            arr.add(new Staff(i, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(),
                    sc.nextLine()));
        Collections.sort(arr);
        for (Staff x : arr)
            System.out.println(x);
    }
}
