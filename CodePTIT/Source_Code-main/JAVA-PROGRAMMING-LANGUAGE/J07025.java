import java.util.*;
import java.io.*;
import java.text.*;

class Customer implements Comparable<Customer> {
    public String code, name, gender, DOB, address;

    public Customer(int orderNumber, String name, String gender, String DOB, String address) {
        this.code = String.format("KH%03d", orderNumber);
        this.name = getFormattedName(name);
        this.gender = gender;
        this.DOB = getFormattedDOB(DOB);
        this.address = address;
    }

    public String getFormattedName(String s) {
        ArrayList<String> word = new ArrayList<>(Arrays.asList(s.trim().toLowerCase().split("\\s+")));
        StringBuilder res = new StringBuilder("");
        for (int i = 0; i < word.size(); i++) {
            StringBuilder tmp = new StringBuilder(word.get(i));
            tmp.setCharAt(0, Character.toUpperCase(tmp.charAt(0)));
            res.append(tmp.append(" "));
        }
        return res.toString().trim();
    }

    public String getFormattedDOB(String s) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        try {
            return sdf.format(sdf.parse(s));
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return "";
    }

    @Override
    public int compareTo(Customer other) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
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

    public String toString() {
        return String.format("%s %s %s %s %s", code, name, gender, address, DOB);
    }
}

public class App {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("KHACHHANG.in"));
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