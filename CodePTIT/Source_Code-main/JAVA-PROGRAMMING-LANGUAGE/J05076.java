import java.util.*;

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, ArrayList<String>> myMap = new HashMap<>();
        int m = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < m; i++) {
            String code = sc.nextLine(), name = sc.nextLine(), type = sc.nextLine();
            myMap.put(code, new ArrayList<>());
            myMap.get(code).add(name);
            myMap.get(code).add(type);
        }
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            String code = sc.next();
            long importQuantity = sc.nextLong(), unitPrice = sc.nextLong(), exportQuantity = sc.nextLong();
            long totalImport = importQuantity * unitPrice;
            String type = myMap.get(code).get(1);
            long totalExport = (unitPrice * exportQuantity)
                    + (unitPrice * exportQuantity) * (type.equals("A") ? 8 : (type.equals("B") ? 5 : 2)) / 100;
            System.out.printf("%s %s %d %d\n", code, myMap.get(code).get(0), totalImport, totalExport);
        }
    }

}
