import java.util.*;

class Lecturer implements Comparable<Lecturer> {
    private String code, name, majors;

    public Lecturer(int orderNumber, String name, String majors) {
        this.code = "GV" + String.format("%02d", orderNumber);
        this.name = name;
        this.majors = majors;
    }

    public String getAcronymOfMajors() {
        String res = "";
        for (int i = 0; i < this.majors.length(); i++) {
            if (i == 0 || this.majors.charAt(i - 1) == ' ')
                res += Character.toUpperCase(majors.charAt(i));
        }
        return res;
    }

    @Override
    public int compareTo(Lecturer other) {
        String name1 = this.name.substring(this.name.lastIndexOf(' ') + 1);
        String name2 = other.name.substring(other.name.lastIndexOf(' ') + 1);
        if (!name1.equals(name2))
            return name1.compareTo(name2);
        return this.code.compareTo(other.code);
    }

    public String toString() {
        return String.format("%s %s %s", this.code, this.name, this.getAcronymOfMajors());
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<Lecturer> arr = new ArrayList<>();
        for (int i = 1; i <= n; i++)
            arr.add(new Lecturer(i, sc.nextLine(), sc.nextLine()));
        Collections.sort(arr);
        for (Lecturer x : arr)
            System.out.println(x);
    }
}
