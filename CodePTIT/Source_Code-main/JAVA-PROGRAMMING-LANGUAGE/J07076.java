import java.io.*;
import java.text.*;
import java.util.*;

public class App {
    public static void main(String[] args) throws ParseException, FileNotFoundException {
        Scanner sc = new Scanner(new File("MATRIX.in"));
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt(), m = sc.nextInt(), colNumber = sc.nextInt();
            colNumber--;
            int matrix[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    matrix[i][j] = sc.nextInt();
            }
            ArrayList<Integer> num = new ArrayList<>();
            for (int i = 0; i < n; i++)
                num.add(matrix[i][colNumber]);
            Collections.sort(num);
            for (int i = 0; i < n; i++)
                matrix[i][colNumber] = num.get(i);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++)
                    System.out.printf("%d ", matrix[i][j]);
                System.out.println();
            }
        }
    }

}
