import java.util.*;

class Matrix {
    private int n, m, a[][];

    public Matrix(int n, int m) {
        this.n = n;
        this.m = m;
        this.a = new int[n][m];
    }

    public void nextMatrix(Scanner sc) {
        for (int i = 0; i < this.n; i++) {
            for (int j = 0; j < this.m; j++)
                this.a[i][j] = sc.nextInt();
        }
    }

    public Matrix trans() {
        Matrix transMatrix = new Matrix(this.m, this.n);
        for (int i = 0; i < this.n; i++) {
            for (int j = 0; j < this.m; j++)
                transMatrix.a[j][i] = this.a[i][j];
        }
        return transMatrix;
    }

    public Matrix mul(Matrix other) {
        Matrix res = new Matrix(this.n, other.m);
        for (int i = 0; i < res.n; i++) {
            for (int j = 0; j < res.m; j++) {
                for (int k = 0; k < this.m; k++)
                    res.a[i][j] += this.a[i][k] * other.a[k][j];
            }
        }
        return res;
    }

    public String toString() {
        StringBuilder print = new StringBuilder("");
        for (int i = 0; i < this.n; i++) {
            for (int j = 0; j < this.m; j++)
                print.append(this.a[i][j] + " ");
            print.append("\n");
        }
        return print.toString();
    }
}

public class App {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
             int n = sc.nextInt(), m = sc.nextInt();
             Matrix a = new Matrix(n,m);
             a.nextMatrix(sc);
             Matrix b = a.trans();
             System.out.println(a.mul(b));
        }
    }
    public static void main7752771(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), m = sc.nextInt();
            Matrix a = new Matrix(n, m);
            a.nextMatrix(sc);
            Matrix b = a.trans();
            System.out.println(a.mul(b));
        }
    }
}
