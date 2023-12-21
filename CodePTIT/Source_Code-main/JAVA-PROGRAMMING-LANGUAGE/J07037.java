import java.util.*;
import java.io.*;

class Enterprise {
    public String code, name, staff;

    public Enterprise(String code, String name, String staff) {
        this.code = code;
        this.name = name;
        this.staff = staff;
    }

    public String toString() {
        return String.format("%s %s %s", this.code, this.name, this.staff);
    }
}

public class App {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("DN.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Enterprise> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Enterprise(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        Collections.sort(arr, new Comparator<Enterprise>() {
            @Override
            public int compare(Enterprise a, Enterprise b) {
                return a.code.compareTo(b.code);
            }
        });
        for (Enterprise x : arr)
            System.out.println(x);
    }
}
