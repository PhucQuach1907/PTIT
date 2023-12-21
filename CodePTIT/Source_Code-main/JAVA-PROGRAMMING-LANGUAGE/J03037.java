import java.util.*;

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String str = sc.next();
        int pos[] = new int[26];
        int cnt[] = new int[26];
        Arrays.fill(pos, -1);
        Arrays.fill(cnt, 0);
        int res = 0;
        for (int i = 0; i < str.length(); i++) {
            int idx = str.charAt(i) - 'A';
            if (pos[idx] == -1) {
                cnt[idx]++;
                pos[idx] = i;
                continue;
            }
            for (int j = pos[idx] + 1; j < i; j++) {
                if (cnt[str.charAt(j) - 'A'] == 1)
                    res++;
            }
            cnt[idx]++;
        }
        System.out.println(res);
    }
}