import java.util.*;

class Company implements Comparable<Company> {
    public String code, name;
    public int numberOfReception;

    public Company(String code, String name, int numberOfReception) {
        this.code = code;
        this.name = name;
        this.numberOfReception = numberOfReception;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d", this.code, this.name, this.numberOfReception);
    }

    public int compareTo(Company other) {
        if (this.numberOfReception != other.numberOfReception)
            return other.numberOfReception - this.numberOfReception;
        return this.code.compareTo(other.code);
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Company> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            sc.nextLine();
            arr.add(new Company(sc.nextLine(), sc.nextLine(), sc.nextInt()));
        }
        int q = sc.nextInt();
        while (q-- > 0) {
            int a = sc.nextInt(), b = sc.nextInt();
            ArrayList<Company> res = new ArrayList<>();
            for (Company x : arr) {
                if (x.numberOfReception >= a && x.numberOfReception <= b)
                    res.add(x);
            }
            Collections.sort(res);
            System.out.printf("DANH SACH DOANH NGHIEP NHAN TU %d DEN %d SINH VIEN:\n", a, b);
            for (Company x : res)
                System.out.println(x);
        }
    }
}