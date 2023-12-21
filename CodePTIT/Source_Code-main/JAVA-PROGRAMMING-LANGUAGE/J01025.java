import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static int Orz(int[] arr, int type, int start) {
        if (type == 0) {
            int res = arr[start];
            for (int i = start; i < 8; i += 2)
                res = Math.min(res, arr[i]);
            return res;
        }
        int res = arr[start];
        for (int i = start; i < 8; i += 2)
            res = Math.max(res, arr[i]);
        return res;
    }

    static void Solve() {
        int rec[] = new int[8];
        for (int i = 0; i < 8; i++)
            rec[i] = sc.nextInt();
        int sz1 = Orz(rec, 1, 0) - Orz(rec, 0, 0);
        int sz2 = Orz(rec, 1, 1) - Orz(rec, 0, 1);
        System.out.println(Math.max(sz1, sz2) * Math.max(sz1, sz2));
    }

    public static void main(String[] args) throws Exception {
        Solve();
    }
}