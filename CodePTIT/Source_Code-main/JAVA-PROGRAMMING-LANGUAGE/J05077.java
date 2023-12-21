import java.util.*;

class Staff {
    public String code, name, roomName;
    public long grade, basicSalary, wordkDays, salary;

    public Staff(String code, String name, long basicSalary, long wordkDays) {
        this.code = code;
        this.name = name;
        this.basicSalary = basicSalary;
        this.wordkDays = wordkDays;
        this.grade = getGrade();
        this.salary = basicSalary * wordkDays * grade * 1000;
    }

    public void setRoomName(String roomName) {
        this.roomName = roomName;
    }

    public long getGrade() {
        Integer[][] gradeTable = { { 10, 12, 14, 20 }, { 10, 11, 13, 16 }, { 9, 10, 12, 14 }, { 8, 9, 11, 13 } };
        int type = code.charAt(0) - 'A';
        int y = Integer.parseInt(code.substring(1, 3));
        if (y >= 16)
            return (long) gradeTable[type][3];
        if (y >= 9)
            return (long) gradeTable[type][2];
        if (y >= 4)
            return (long) gradeTable[type][1];
        return (long) gradeTable[type][0];
    }

    @Override
    public String toString() {
        return String.format("%s %s %s %d", code, name, roomName, salary);
    }
}

public class App {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String, String> myMap = new HashMap<>();
        int m = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < m; i++) {
            String tmp = sc.nextLine();
            myMap.put(tmp.substring(0, 2), tmp.substring(3));
        }
        int n = sc.nextInt();
        ArrayList<Staff> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            String code = sc.nextLine();
            String name = sc.nextLine();
            long basicSalary = sc.nextLong(), wordkDays = sc.nextLong();
            arr.add(new Staff(code, name, basicSalary, wordkDays));
        }
        for (int i = 0; i < n; i++)
            arr.get(i).setRoomName(myMap.get(arr.get(i).code.substring(3)));
        for (Staff x : arr)
            System.out.println(x);
    }

}
