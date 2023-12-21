import java.util.*;
import java.io.*;;

class Subject {
    String code, name, form;

    public Subject(String code, String name, String form) {
        this.code = code;
        this.name = name;
        this.form = form;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s", this.code, this.name, this.form);
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
            public int compare(Subject x, Subject y) {
                return x.code.compareTo(y.code);
            }
        });
        for (Subject x : arr)
            System.out.println(x);
    }
}