import java.util.*;
import static java.lang.Math.*;

class Rectangle {
    private int x;
    private int y;
    private String color;

    public Rectangle(int x, int y, String color) {
        this.x = x;
        this.y = y;
        this.color = color;
    }

    public boolean isRectangle() {
        return this.x > 0 && this.y > 0;
    }

    @Override
    public String toString() {
        if (!isRectangle())
            return "INVALID";
        else {
            StringBuilder clr = new StringBuilder(this.color.toLowerCase());
            clr.setCharAt(0, Character.toUpperCase(clr.charAt(0)));
            return String.format("%d %d %s", (x + y) * 2, x * y, clr);
        }
    }
}

public class App {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        int a = sc.nextInt(), b = sc.nextInt();
        String color = sc.next();
        Rectangle rect = new Rectangle(a, b, color);
        System.out.println(rect);
    }
}
