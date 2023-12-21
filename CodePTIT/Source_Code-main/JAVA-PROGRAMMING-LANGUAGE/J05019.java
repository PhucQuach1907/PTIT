import java.text.*;
import java.util.*;
import java.util.concurrent.TimeUnit;

public class App {
    private static Scanner sc = new Scanner(System.in);

    static int getTimeInMinutes(String start, String stop) {
        SimpleDateFormat sdf = new SimpleDateFormat("hh:mm");
        try {
            Date d1 = sdf.parse(start), d2 = sdf.parse(stop);
            long diffInMillies = d2.getTime() - d1.getTime();
            return (int) TimeUnit.MINUTES.convert(diffInMillies, TimeUnit.MILLISECONDS);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return -1;
    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        HashMap<String, String> hashCode = new HashMap<>();
        HashMap<String, ArrayList<Integer>> hashInfo = new HashMap<>();
        ArrayList<String> cityList = new ArrayList<>();
        int idx = 1;
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            String city = sc.nextLine();
            int rangeTime = getTimeInMinutes(sc.nextLine(), sc.nextLine());
            int rainAmount = sc.nextInt();
            if (!hashCode.containsKey(city)) {
                hashCode.put(city, String.format("T%02d", idx++));
                hashInfo.put(city, new ArrayList<>());
                hashInfo.get(city).add(rainAmount);
                hashInfo.get(city).add(rangeTime);
                cityList.add(city);
            } else {
                int curRain = hashInfo.get(city).get(0), curTime = hashInfo.get(city).get(1);
                hashInfo.get(city).set(0, curRain + rainAmount);
                hashInfo.get(city).set(1, curTime + rangeTime);
            }
        }
        for (String x : cityList) {
            String code = hashCode.get(x);
            int totalRainAmount = hashInfo.get(x).get(0);
            int totalTime = hashInfo.get(x).get(1);
            double averageRain = (totalRainAmount * 1.0 / totalTime) * 60;
            System.out.printf("%s %s %.2f\n", code, x, averageRain);
        }
    }

}
