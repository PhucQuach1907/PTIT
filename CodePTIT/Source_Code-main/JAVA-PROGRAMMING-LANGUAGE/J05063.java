import java.util.*;

class DaThuc {
    private String data;

    public DaThuc(String data) {
        this.data = data;
    }

    public DaThuc cong(DaThuc other) {
        ArrayList<String> element = new ArrayList<>(Arrays.asList(this.data.split(" ")));
        element.addAll(new ArrayList<>(Arrays.asList(other.data.split(" "))));
        while (element.contains("+"))
            element.remove("+");
        SortedMap<Integer, Integer> add = new TreeMap<>(Collections.reverseOrder());
        for (String x : element) {
            int factor = Integer.parseInt(x.substring(0, x.indexOf("*")));
            int exp = Integer.parseInt(x.substring(x.indexOf("^") + 1));
            if (add.containsKey(exp))
                add.put(exp, add.get(exp) + factor);
            else
                add.put(exp, factor);
        }
        StringBuilder res = new StringBuilder("");
        add.forEach((key, value) -> {
            res.append(String.format("%d*x^%d", value, key));
            res.append(" + ");
        });
        res.delete(res.lastIndexOf(" + "), res.length());
        return new DaThuc(res.toString());
    }

    @Override
    public String toString() {
        return this.data;
    }
}

public class App {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) {
            DaThuc p = new DaThuc(sc.nextLine());
            DaThuc q = new DaThuc(sc.nextLine());
            DaThuc r = p.cong(q);
            System.out.println(r);
        }
    }
}
