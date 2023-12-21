import java.io.*;
import java.util.*;

class Student {
    public String code, name, className, email;

    public Student(String code, String name, String className, String email) {
        this.code = code;
        this.name = getFormattedName(name);
        this.className = className;
        this.email = email;
    }

    public String getFormattedName(String nm) {
        ArrayList<String> tmp = new ArrayList<>(Arrays.asList(nm.trim().toLowerCase().split("\\s+")));
        StringBuilder formattedName = new StringBuilder("");
        for (int i = 0; i < tmp.size(); i++) {
            StringBuilder w = new StringBuilder(tmp.get(i));
            w.setCharAt(0, Character.toUpperCase(w.charAt(0)));
            formattedName.append(w + " ");
        }
        return formattedName.toString().trim();
    }
}

class Company {
    public String code, name;
    public int numberOfReception;

    public Company(String code, String name, int numberOfReception) {
        this.code = code;
        this.name = name;
        this.numberOfReception = numberOfReception;
    }
}

class DataInternship {
    public Student intern;

    public DataInternship(Student intern) {
        this.intern = intern;
    }

    @Override
    public String toString() {
        return String.format("%s %s %s", intern.code, intern.name, intern.className);
    }
}

public class App {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("SINHVIEN.in"));
        int n = sc.nextInt();
        sc.nextLine();
        HashMap<String, Student> hashStudent = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String code = sc.nextLine();
            hashStudent.put(code, new Student(code, sc.nextLine(), sc.nextLine(), sc.nextLine()));
        }
        sc = new Scanner(new File("DN.in"));
        n = sc.nextInt();
        HashMap<String, Company> hashCompany = new HashMap<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            String code = sc.nextLine();
            hashCompany.put(code, new Company(code, sc.nextLine(), sc.nextInt()));
        }
        sc = new Scanner(new File("THUCTAP.in"));
        n = sc.nextInt();
        ArrayList<ArrayList<String>> internship = new ArrayList<>();
        for (int i = 0; i < n; i++)
            internship.add(new ArrayList<>());
        for (int i = 0; i < n; i++) {
            internship.get(i).add(sc.next());
            internship.get(i).add(sc.next());
        }
        int q = sc.nextInt();
        while (q-- > 0) {
            String companyCode = sc.next();
            ArrayList<DataInternship> res = new ArrayList<>();
            for (ArrayList<String> x : internship) {
                if (x.get(1).equals(companyCode))
                    res.add(new DataInternship(hashStudent.get(x.get(0))));
            }
            res.sort((x, y) -> {
                return x.intern.code.compareTo(y.intern.code);
            });
            int reception = Math.min(hashCompany.get(companyCode).numberOfReception, res.size());
            System.out.printf("DANH SACH THUC TAP TAI %s:\n", hashCompany.get(companyCode).name);
            for (int i = 0; i < reception; i++)
                System.out.println(res.get(i));
        }
    }

}
