import java.util.*;

class Match {
    public String code, teamName;
    public long turnover;

    public Match(String code, String teamName, long turnover) {
        this.code = code;
        this.teamName = teamName;
        this.turnover = turnover;
    }

    @Override
    public String toString() {
        return String.format("%s %s %d", code, teamName, turnover);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        sc.nextLine();
        HashMap<String, ArrayList<String>> myMap = new HashMap<>();
        for (int i = 0; i < m; i++) {
            String code = sc.nextLine(), name = sc.nextLine(), ticketPrice = sc.nextLine();
            myMap.put(code, new ArrayList<>());
            myMap.get(code).add(name);
            myMap.get(code).add(ticketPrice);
        }
        int n = sc.nextInt();
        ArrayList<Match> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String code = sc.next();
            String tmp = code.substring(1, 3);
            long viewers = sc.nextLong();
            arr.add(new Match(code, myMap.get(tmp).get(0), viewers * Long.parseLong(myMap.get(tmp).get(1))));
        }
        for (Match x : arr)
            System.out.println(x);
    }

}