import java.util.*;

class Phone {
    public String phoneNumber, province;
    public int timeCalling, cost;

    public Phone(String phoneNumber, String timeStart, String timeStop, String province, int price) {
        this.phoneNumber = phoneNumber;
        this.province = province;
        int rangeTime = (Integer.parseInt(timeStop.substring(0, 2)) * 60 + Integer.parseInt(timeStop.substring(3)))
                - (Integer.parseInt(timeStart.substring(0, 2)) * 60 + Integer.parseInt(timeStart.substring(3)));
        if (phoneNumber.charAt(0) == '0') {
            this.timeCalling = rangeTime;
        } else {
            this.timeCalling = (int) Math.round(rangeTime * 1.0 / 3);
        }
        this.cost = price * timeCalling;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d %d", phoneNumber, province, timeCalling, cost);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int m = sc.nextInt();
        sc.nextLine();
        HashMap<String, ArrayList<String>> info = new HashMap<>();
        for (int i = 0; i < m; i++) {
            String code = sc.nextLine(), name = sc.nextLine(), price = sc.nextLine();
            info.put(code, new ArrayList<>());
            info.get(code).add(name);
            info.get(code).add(price);
        }
        int n = sc.nextInt();
        ArrayList<Phone> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String phoneNumber = sc.next(), timeStart = sc.next(), timeStop = sc.next();
            String province = !phoneNumber.startsWith("0") ? "Noi mang" : info.get(phoneNumber.substring(1, 3)).get(0);
            int price = !phoneNumber.startsWith("0") ? 800
                    : Integer.parseInt(info.get(phoneNumber.substring(1, 3)).get(1));
            arr.add(new Phone(phoneNumber, timeStart, timeStop, province, price));
        }
        for (Phone x : arr)
            System.out.println(x);
    }

}
