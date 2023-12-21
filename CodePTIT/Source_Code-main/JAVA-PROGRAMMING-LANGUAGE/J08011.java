import java.util.*;

class Data {
    public String num;
    public int fre, firstAppear;

    public Data(String num, int fre, int firstAppear) {
        this.num = num;
        this.fre = fre;
        this.firstAppear = firstAppear;
    }

    @Override
    public String toString() {
        return num + " " + fre;
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    static boolean Check(String s) {
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) < s.charAt(i - 1))
                return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        HashMap<String, ArrayList<Integer>> cnt = new HashMap<>();
        int idx = 1;
        while (sc.hasNext()) {
            String num = sc.next();
            if (Check(num)) {
                if (!cnt.containsKey(num)) {
                    cnt.put(num, new ArrayList<>());
                    cnt.get(num).add(1);
                    cnt.get(num).add(idx);
                } else {
                    int prevCnt = cnt.get(num).get(0);
                    cnt.get(num).set(0, prevCnt + 1);
                }
            }
            idx += 1;
        }
        ArrayList<Data> arr = new ArrayList<>();
        cnt.forEach((key, value) -> {
            arr.add(new Data(key, value.get(0), value.get(1)));
        });
        arr.sort((x, y) -> {
            if (x.fre != y.fre)
                return y.fre - x.fre;
            return x.firstAppear - y.firstAppear;
        });
        for (Data x : arr)
            System.out.println(x);
    }
}
