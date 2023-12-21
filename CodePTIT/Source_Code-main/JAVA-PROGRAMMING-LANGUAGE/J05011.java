import java.util.*;

class Gamer implements Comparable<Gamer> {
    private String code, name, timeStart, timeStop;

    public Gamer(String code, String name, String timeStart, String timeStop) {
        this.code = code;
        this.name = name;
        this.timeStart = timeStart;
        this.timeStop = timeStop;
    }

    public int getDiffInMinutes() {
        int startMinutes = Integer.parseInt(this.timeStart.substring(0, 2)) * 60
                + Integer.parseInt(this.timeStart.substring(3));
        int stopMinutes = Integer.parseInt(this.timeStop.substring(0, 2)) * 60
                + Integer.parseInt(this.timeStop.substring(3));
        return stopMinutes - startMinutes;
    }

    public String getTimeBetween() {
        int diff = this.getDiffInMinutes();
        int hours = diff / 60;
        int minutes = diff - 60 * hours;
        return String.format("%d gio %d phut", hours, minutes);
    }

    @Override
    public String toString() {
        return String.format("%s %s %s", this.code, this.name, this.getTimeBetween());
    }

    public int compareTo(Gamer other) {
        return other.getDiffInMinutes() - this.getDiffInMinutes();
    }

}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Gamer> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Gamer(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        Collections.sort(arr);
        for (Gamer x : arr)
            System.out.println(x);
    }
}
