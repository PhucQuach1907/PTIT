import java.util.*;

class WordSet {
    private SortedSet<String> word;

    public WordSet(String s) {
        this.word = new TreeSet<>(new ArrayList<>(Arrays.asList(s.toLowerCase().split(" "))));
    }

    public WordSet union(WordSet other) {
        StringBuilder tmp = new StringBuilder("");
        for (String x : this.word)
            tmp.append(x + " ");
        for (String x : other.word)
            tmp.append(x + " ");
        tmp.deleteCharAt(tmp.length() - 1);
        return new WordSet(tmp.toString());
    }

    public WordSet intersection(WordSet other) {
        StringBuilder tmp = new StringBuilder("");
        for (String x : this.word) {
            if (other.word.contains(x))
                tmp.append(x + " ");
        }
        tmp.deleteCharAt(tmp.length() - 1);
        return new WordSet(tmp.toString());
    }

    @Override
    public String toString() {
        StringBuilder print = new StringBuilder("");
        for (String x : this.word)
            print.append(x + " ");
        return print.toString();
    }
}

public class App {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        WordSet s1 = new WordSet(in.nextLine());
        WordSet s2 = new WordSet(in.nextLine());
        System.out.println(s1.union(s2));
        System.out.println(s1.intersection(s2));
    }
}
