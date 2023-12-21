import java.io.*;
import java.text.*;
import java.util.*;

class User implements Comparable<User> {
    public String code, name, type;
    public int electricNumber;

    public User(int orderNumber, String name, String type, int first, int last) {
        this.code = "KH" + String.format("%02d", orderNumber);
        this.name = name;
        this.type = type;
        this.electricNumber = last - first;
    }

    public String getFormattedName() {
        ArrayList<String> tmp = new ArrayList<>(Arrays.asList(this.name.trim().toLowerCase().split("\\s+")));
        StringBuilder formattedName = new StringBuilder("");
        for (int i = 0; i < tmp.size(); i++) {
            StringBuilder w = new StringBuilder(tmp.get(i));
            w.setCharAt(0, Character.toUpperCase(w.charAt(0)));
            formattedName.append(w + " ");
        }
        return formattedName.toString().trim();
    }

    public int getNorm() {
        if (this.type.equals("A"))
            return 100;
        if (this.type.equals("B"))
            return 500;
        return 200;
    }

    public int getInNorm() {
        return (this.electricNumber <= this.getNorm() ? this.electricNumber * 450 : this.getNorm() * 450);
    }

    public int getOverNorm() {
        return (this.electricNumber > this.getNorm() ? (this.electricNumber - this.getNorm()) * 1000 : 0);
    }

    public int getVAT() {
        return 5 * this.getOverNorm() / 100;
    }

    public int getTotalCost() {
        return this.getInNorm() + this.getOverNorm() + this.getVAT();
    }

    @Override
    public int compareTo(User other) {
        return other.getTotalCost() - this.getTotalCost();
    }

    public String toString() {
        return String.format("%s %s %d %d %d %d", this.code, this.getFormattedName(), this.getInNorm(),
                this.getOverNorm(), this.getVAT(), this.getTotalCost());
    }
}

public class App {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("KHACHHANG.in"));
        int n = sc.nextInt();
        ArrayList<User> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            arr.add(new User(i + 1, sc.nextLine(), sc.next(), sc.nextInt(), sc.nextInt()));
        }
        Collections.sort(arr);
        for (User x : arr)
            System.out.println(x);
    }

}
