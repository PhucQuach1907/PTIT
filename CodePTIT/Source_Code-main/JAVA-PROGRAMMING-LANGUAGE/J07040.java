import java.util.*;
import java.io.*;

public class App {

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream("NHIPHAN.in"));
        List<String> arr = (ArrayList<String>) ois.readObject();
        ArrayList<String> binaryFileWords = new ArrayList<>();
        for (String x : arr)
            binaryFileWords.addAll(Arrays.asList(x.trim().toLowerCase().split("\\s+")));
        Scanner sc = new Scanner(new File("VANBAN.in"));
        ArrayList<String> textFileWords = new ArrayList<>();
        while (sc.hasNextLine()) {
            String x = sc.nextLine().trim().toLowerCase();
            textFileWords.addAll(Arrays.asList(x.split("\\s+")));
        }
        ArrayList<String> res = new ArrayList<>();
        for (String word : textFileWords) {
            if (binaryFileWords.contains(word) && !res.contains(word))
                res.add(word);
        }
        for (String x : res)
            System.out.println(x);
    }
}
