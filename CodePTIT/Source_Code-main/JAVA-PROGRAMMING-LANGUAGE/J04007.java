import java.util.*;
import java.text.SimpleDateFormat;
import static java.lang.Math.*;

class Staff {
    private String orderNumber, name, gender, DOB, address, phoneNumber, dateContractor;

    public Staff(String name, String gender, String DOB, String address, String phoneNumber, String dateContractor) {
        this.name = name;
        this.gender = gender;
        this.DOB = DOB;
        this.address = address;
        this.phoneNumber = phoneNumber;
        this.dateContractor = dateContractor;
        this.orderNumber = "00001";
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %s %s %s", this.orderNumber, this.name, this.gender, this.DOB, this.address,
                this.phoneNumber, this.dateContractor);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String name = sc.nextLine();
        String gender = sc.nextLine();
        String DOB = sc.nextLine();
        String address = sc.nextLine();
        String phoneNumber = sc.nextLine();
        String dateContractor = sc.nextLine();
        Staff a = new Staff(name, gender, DOB, address, phoneNumber, dateContractor);
        System.out.println(a);
    }
}