import java.util.*;

class IntSet {
    private SortedSet<Integer> mySet;

    public IntSet(int a[]) {
        this.mySet = new TreeSet<>();
        for (int i = 0; i < a.length; i++)
            mySet.add(a[i]);
    }

    public IntSet union(IntSet other) {
        int merge[] = new int[this.mySet.size() + other.mySet.size()], i = 0;
        for (Integer x : this.mySet)
            merge[i++] = x;
        for (Integer x : other.mySet)
            merge[i++] = x;
        return new IntSet(merge);
    }

    @Override
    public String toString() {
        StringBuilder pr = new StringBuilder("");
        for (Integer x : this.mySet)
            pr.append(x + " ");
        return pr.toString();
    }
}

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), a[] = new int[n], b[] = new int[m];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        for (int i = 0; i < m; i++)
            b[i] = sc.nextInt();
        IntSet s1 = new IntSet(a);
        IntSet s2 = new IntSet(b);
        IntSet s3 = s1.union(s2);
        System.out.println(s3);
    }
}