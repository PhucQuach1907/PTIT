import java.text.*;
import java.util.*;

class Athlete {
    public String code, name, DOB, start, finish;
    public String actualAchievement, prioritized, finalAchievement;
    public int diffInSeconds, finalDiff, rank;

    public Athlete(int orderNumber, String name, String DOB, String start, String finish) {
        this.code = String.format("VDV%02d", orderNumber);
        this.name = name;
        this.DOB = DOB;
        this.start = start;
        this.finish = finish;
        this.diffInSeconds = getDiffInSeconds();
        this.finalDiff = getFinalDiff();
        this.actualAchievement = getActualAchievement();
        this.prioritized = getPrioritized();
        this.finalAchievement = getFinalAchievement();
    }

    public int getDiffInSeconds() {
        SimpleDateFormat sdf = new SimpleDateFormat("hh:mm:ss", Locale.ENGLISH);
        Date f, s;
        try {
            f = sdf.parse(start);
            s = sdf.parse(finish);
            long diffInMillies = Math.abs(s.getTime() - f.getTime());
            return (int) diffInMillies / 1000;
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return 0;
    }

    public int getPriorityInSecond() {
        int age = 2021 - Integer.parseInt(DOB.substring(DOB.lastIndexOf('/') + 1));
        if (age > 32)
            return 3;
        if (age >= 25)
            return 2;
        if (age >= 18)
            return 1;
        return 0;
    }

    public int getFinalDiff() {
        return diffInSeconds - getPriorityInSecond();
    }

    public String getActualAchievement() {
        return String.format("%02d:%02d:%02d", diffInSeconds / 3600, (diffInSeconds % 3600) / 60, (diffInSeconds % 60));
    }

    public String getPrioritized() {
        int priorityInSecond = getPriorityInSecond();
        return String.format("%02d:%02d:%02d", priorityInSecond / 3600, (priorityInSecond % 3600) / 60,
                (priorityInSecond % 60));
    }

    public String getFinalAchievement() {
        return String.format("%02d:%02d:%02d", finalDiff / 3600, (finalDiff % 3600) / 60,
                (finalDiff % 60));
    }

    public void setRank(int rank) {
        this.rank = rank;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %s %s %d", code, name, actualAchievement, prioritized, finalAchievement, rank);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Athlete> arr = new ArrayList<>();
        sc.nextLine();
        for (int i = 1; i <= n; i++)
            arr.add(new Athlete(i, sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine()));
        arr.sort((x, y) -> {
            return x.finalDiff - y.finalDiff;
        });
        for (int i = 0; i < n; i++)
            arr.get(i).setRank(i + 1);
        for (int i = 1; i < n; i++) {
            if (arr.get(i).finalDiff == arr.get(i - 1).finalDiff)
                arr.get(i).setRank(arr.get(i - 1).rank);
        }
        arr.sort((x, y) -> {
            return x.code.compareTo(y.code);
        });
        for (Athlete x : arr)
            System.out.println(x);
    }
}
