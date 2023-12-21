import java.util.*;
import java.io.*;;

class Checkin {
    public int cur, cost;

    public Checkin(int cur, int cost) {
        this.cur = cur;
        this.cost = cost;
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        int n = sc.nextInt();
        ArrayList<Checkin> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Checkin(sc.nextInt(), sc.nextInt()));
        Collections.sort(arr, new Comparator<Checkin>() {
            @Override
            public int compare(Checkin x, Checkin y) {
                return x.cur - y.cur;
            }
        });
        int res = arr.get(0).cur + arr.get(0).cost;
        for (int i = 1; i < n; i++) {
            Checkin tmp = arr.get(i);
            if (tmp.cur < res)
                res += tmp.cost;
            else
                res = tmp.cur + tmp.cost;
        }
        System.out.println(res);
    }
}