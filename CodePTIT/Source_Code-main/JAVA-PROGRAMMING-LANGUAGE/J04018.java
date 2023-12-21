import java.util.*;
import java.io.*;

class Complex {
    private int real, img;

    public Complex(int real, int img) {
        this.real = real;
        this.img = img;
    }

    public Complex add(Complex other) {
        return new Complex(this.real + other.real, this.img + other.img);
    }

    public Complex multiply(Complex other) {
        return new Complex(this.real * other.real - this.img * other.img,
                this.real * other.img + this.img * other.real);
    }

    @Override
    public String toString() {
        return String.format("%d %s %di", this.real, this.img > 0 ? "+" : "-", Math.abs(this.img));
    }
}

public class App {
    private static Scanner sc = new Scanner(System.in);

    static void Solve() {
        int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt(), d = sc.nextInt();
        Complex A = new Complex(a, b), B = new Complex(c, d);
        Complex C = A.add(B).multiply(A);
        Complex D = (A.add(B)).multiply((A.add(B)));
        System.out.println(C + ", " + D);
    }

    public static void main(String[] args) throws IOException {
        int t = sc.nextInt();
        while (t-- > 0)
            Solve();
    }
}
