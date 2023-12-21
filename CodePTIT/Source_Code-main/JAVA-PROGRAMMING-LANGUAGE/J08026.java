import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int s = sc.nextInt(), t = sc.nextInt();
        if (s > t) {
            System.out.println(s - t);
            return;
        }
        int step[] = new int[20005];
        Arrays.fill(step, 0);
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        while (!q.isEmpty()) {
            int cur = q.remove();
            if (cur == t) {
                System.out.println(step[cur]);
                return;
            }
            if (cur < t && step[cur * 2] == 0) {
                q.add(cur * 2);
                step[cur * 2] = step[cur] + 1;
            }
            if (cur - 1 > 0 && step[cur - 1] == 0) {
                q.add(cur - 1);
                step[cur - 1] = step[cur] + 1;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0)
            Solve();
    }
}
