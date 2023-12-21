import java.io.*;
import java.text.*;
import java.util.*;

class Examination {
    public String code, date, time, roomId;

    public Examination(int orderNumber, String date, String time, String roomId) {
        this.code = "C" + String.format("%03d", orderNumber);
        this.date = date;
        this.time = time;
        this.roomId = roomId;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s", this.code, this.date, this.time, this.roomId);
    }
}

public class App {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("CATHI.in"));
        int n = sc.nextInt();
        ArrayList<Examination> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            arr.add(new Examination(i, sc.next(), sc.next(), sc.next()));
        Collections.sort(arr, new Comparator<Examination>() {
            @Override
            public int compare(Examination ex1, Examination ex2) {
                String d1 = ex1.date + " " + ex1.time;
                String d2 = ex2.date + " " + ex2.time;
                if (d1.equals(d2))
                    return ex1.code.compareTo(ex2.code);
                DateFormat f = new SimpleDateFormat("dd/MM/yyyy hh:mm");
                try {
                    return f.parse(ex1.date + " " + ex1.time).compareTo(f.parse(ex2.date + " " + ex2.time));
                } catch (ParseException e) {
                    e.printStackTrace();
                }
                return 0;
            }
        });
        for (Examination x : arr)
            System.out.println(x);
    }

}
