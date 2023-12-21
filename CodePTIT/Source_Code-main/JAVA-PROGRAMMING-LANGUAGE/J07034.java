import java.util.*;
import java.io.*;

class Subject {
    public String code, name, tc;

    public Subject(String code, String name, String tc) {
        this.code = code;
        this.name = name;
        this.tc = tc;
    }

    public String toString() {
        return String.format("%s %s %s", this.code, this.name, this.tc);
    }
}

public class App {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("MONHOC.in"));
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Subject> arr = new ArrayList<>();
        for (int i = 0; i < n; i++)
            arr.add(new Subject(sc.nextLine(), sc.nextLine(), sc.nextLine()));
        Collections.sort(arr, new Comparator<Subject>() {
            @Override
            public int compare(Subject a, Subject b) {
                return a.name.compareTo(b.name);
            }
        });
        for (Subject x : arr)
            System.out.println(x);
    }
}
