import java.text.*;
import java.util.*;

class Person implements Comparable<Person> {
    public String name, DOB;

    public Person(String name, String DOB) {
        this.name = name;
        this.DOB = DOB;
    }

    @Override
    public String toString() {
        return this.name;
    }

    public int compareTo(Person other) {
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        Date d1, d2;
        try {
            d1 = sdf.parse(this.DOB);
            d2 = sdf.parse(other.DOB);
            return d2.compareTo(d1);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return 0;
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        ArrayList<Person> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            arr.add(new Person(sc.next(), sc.next()));
        Collections.sort(arr);
        System.out.println(arr.get(0).name);
        System.out.println(arr.get(n - 1).name);
    }
}