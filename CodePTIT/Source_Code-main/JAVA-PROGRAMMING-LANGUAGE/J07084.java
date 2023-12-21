import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.io.File;
import java.io.FileNotFoundException;
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.Date;

class Student implements Comparable<Student> {
    private String name;
    private int minute_online;

    Student(String name, String src, String dest) {
        this.name = name;
        long seconds = getSecond(src, dest);
        minute_online = (int) seconds / 60;
    }

    private static long getSecond(String src, String dest) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        try {
            Date d1 = sdf.parse(src);
            Date d2 = sdf.parse(dest);
            return (d2.getTime() - d1.getTime()) / 1000;
        }

        catch (ParseException e) {
            return 0;
        }
    }

    public String getName() {
        return name;
    }

    public int getMinuteOnline() {
        return minute_online;
    }

    @Override
    public int compareTo(Student obj) {
        int m = obj.getMinuteOnline() - minute_online;
        if (m != 0)
            return m;
        else
            return name.compareTo(obj.getName());
    }

    @Override
    public String toString() {
        return name + " " + minute_online;
    }
}

public class App {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("ONLINE.in"));
            ArrayList<Student> vec = new ArrayList<>();
            int n = Integer.parseInt(sc.nextLine());
            while (n-- > 0) {
                String name = sc.nextLine(), src = sc.nextLine(), dest = sc.nextLine();
                vec.add(new Student(name, src, dest));
            }

            Collections.sort(vec);
            for (Student s : vec)
                System.out.println(s);
        }

        catch (FileNotFoundException e) {

        }
    }
}
