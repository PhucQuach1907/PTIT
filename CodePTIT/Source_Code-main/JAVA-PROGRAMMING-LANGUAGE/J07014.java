import java.io.*;
import java.util.*;

class WordSet {
    public SortedSet<String> nmc;

    public WordSet() {
        nmc = new TreeSet<>();
    }

    public WordSet(String fileName) throws FileNotFoundException {
        Scanner sc = new Scanner(new File(fileName));
        nmc = new TreeSet<>();
        while (sc.hasNext())
            nmc.add(sc.next().toLowerCase());
    }

    public WordSet union(WordSet other) {
        WordSet res = new WordSet();
        for (String x : this.nmc)
            res.nmc.add(x);
        for (String x : other.nmc)
            res.nmc.add(x);
        return res;
    }

    public WordSet intersection(WordSet other) {
        WordSet res = new WordSet();
        for (String x : this.nmc) {
            if (other.nmc.contains(x))
                res.nmc.add(x);
        }
        return res;
    }

    @Override
    public String toString() {
        StringBuilder print = new StringBuilder("");
        for (String x : nmc)
            print.append(x + " ");
        return print.toString().trim();
    }
}

public class App {
    public static void main(String[] args) throws IOException {
        WordSet s1 = new WordSet("DATA1.in");
        WordSet s2 = new WordSet("DATA2.in");
        System.out.println(s1.union(s2));
        System.out.println(s1.intersection(s2));
    }
    public static void main7774904(String[] args) throws IOException {
        WordSet s1 = new WordSet("DATA1.in");
        WordSet s2 = new WordSet("DATA2.in");
        System.out.println(s1.union(s2));
        System.out.println(s1.intersection(s2));
    }

}
