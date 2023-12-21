import java.util.*;

class Racer {
    public String code, name, address, timeFinish;
    public int velocity;

    public Racer(String name, String address, String timeFinish) {
        this.name = name;
        this.address = address;
        this.timeFinish = timeFinish;
        this.code = getCode();
        this.velocity = getVelocity();
    }

    public String getCode() {
        StringBuilder res = new StringBuilder("");
        for (int i = 0; i < address.length(); i++) {
            if (i == 0 || address.charAt(i - 1) == ' ')
                res.append(Character.toUpperCase(address.charAt(i)));
        }
        for (int i = 0; i < name.length(); i++) {
            if (i == 0 || name.charAt(i - 1) == ' ')
                res.append(Character.toUpperCase(name.charAt(i)));
        }
        return res.toString();
    }

    public int getVelocity() {
        int timeInMinutes = Integer.parseInt(timeFinish.substring(0, 1)) * 60
                + Integer.parseInt(timeFinish.substring(2)) - 360;
        double timeInHours = timeInMinutes * 1.0 / 60;
        return (int) Math.round(120 * 1.0 / timeInHours);
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %d Km/h", code, name, address, velocity);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Racer> arr = new ArrayList<>();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            arr.add(new Racer(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        arr.sort((x, y) -> {
            return x.timeFinish.compareTo(y.timeFinish);
        });
        for (Racer x : arr)
            System.out.println(x);
    }
}
