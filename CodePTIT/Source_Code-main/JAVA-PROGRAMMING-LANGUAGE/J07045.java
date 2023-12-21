import java.util.*;
import java.io.*;

class LoaiPhong implements Comparable<LoaiPhong> {
    public String type, name;
    public int dayUnitPrice;
    public double chargeService;

    public LoaiPhong(String infomation) {
        ArrayList<String> tmp = new ArrayList<>(Arrays.asList(infomation.split(" ")));
        this.type = tmp.get(0);
        this.name = tmp.get(1);
        this.dayUnitPrice = Integer.parseInt(tmp.get(2));
        this.chargeService = Double.parseDouble(tmp.get(3));
    }

    public String toString() {
        return String.format("%s %s %d %.2f", this.type, this.name, this.dayUnitPrice, this.chargeService);
    }

    @Override
    public int compareTo(LoaiPhong other) {
        return this.name.compareTo(other.name);
    }
}

public class App {

    public static void main(String[] args) throws IOException {
        ArrayList<LoaiPhong> ds = new ArrayList<>();
        Scanner in = new Scanner(new File("PHONG.in"));
        int n = Integer.parseInt(in.nextLine());
        while (n-- > 0) {
            ds.add(new LoaiPhong(in.nextLine()));
        }
        Collections.sort(ds);
        for (LoaiPhong tmp : ds) {
            System.out.println(tmp);
        }
    }
}
