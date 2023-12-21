import java.util.*;

class Time {
    public int h, m, s;

    public Time(int h, int m, int s) {
        this.h = h;
        this.m = m;
        this.s = s;
    }

    @Override
    public String toString() {
        return String.format("%d %d %d", this.h, this.m, this.s);
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Time> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Time e = new Time(sc.nextInt(), sc.nextInt(), sc.nextInt());
            arr.add(e);
        }
        Collections.sort(arr, new Comparator<Time>() {
            @Override
            public int compare(Time x, Time y) {
                if (x.h != y.h)
                    return x.h - y.h;
                if (x.m != y.m)
                    return x.m - y.m;
                return x.s - y.s;
            }
        });
        for (Time t : arr)
            System.out.println(t);
    }
}
