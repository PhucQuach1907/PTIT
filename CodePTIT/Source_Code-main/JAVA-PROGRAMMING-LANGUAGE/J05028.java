import java.util.*;

class Company {
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
        Collections.sort(arr, new Comparator<Company>() {
            @Override
            public int compare(Company x, Company y) {
                if (x.numberOfReception != y.numberOfReception)
                    return y.numberOfReception - x.numberOfReception;
                return x.code.compareTo(y.code);
            }
        });
        for (Company x : arr)
            System.out.println(x);
    }
}