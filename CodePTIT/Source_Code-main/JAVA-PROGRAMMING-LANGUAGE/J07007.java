import java.util.*;
import java.io.*;

class WordSet {
    private SortedSet<String> diff;

    public WordSet(String src) throws FileNotFoundException {
        ArrayList<String> arr = new ArrayList<>();
        Scanner sc = new Scanner(new File(src));
        while (sc.hasNext())
            arr.add(sc.next().toLowerCase());
        this.diff = new TreeSet<>(arr);
    }

    public String toString() {
        StringBuilder print = new StringBuilder("");
        for (String x : this.diff)
            print.append(x + "\n");
        return print.toString();
    }
}

public class App {
    public static void main(String[] args) throws IOException {
        WordSet ws = new WordSet("VANBAN.in");
        System.out.println(ws);
    }
}
