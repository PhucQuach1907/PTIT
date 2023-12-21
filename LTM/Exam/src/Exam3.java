import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.List;

public class Exam3 {
    public static void main(String[] args) {
        String serverHost = "localhost"; // Đổi thành địa chỉ IP hoặc tên miền của server
        int serverPort = 8080;

        try {
            // Kết nối đến server
            Socket socket = new Socket(serverHost, serverPort);
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            // Gửi mã sinh viên và mã câu hỏi đến server
            String maSV = "B15DCCN999";
            int maCauHoi = 600;
            String request = maSV + ";" + maCauHoi;
            out.write(request);
            out.newLine();
            out.flush();

            // Nhận danh sách tên miền từ server
            List<String> domainList = new ArrayList<>();
            String response;
            while ((response = in.readLine()) != null) {
                domainList.add(response);
            }

            // Tìm kiếm và gửi tên miền .edu đến server
            List<String> eduDomains = new ArrayList<>();
            for (String domain : domainList) {
                if (domain.endsWith(".edu")) {
                    eduDomains.add(domain);
                }
            }

            // Gửi danh sách tên miền .edu đến server
            for (String eduDomain : eduDomains) {
                out.write(eduDomain);
                out.newLine();
                out.flush();
            }

            // Đóng kết nối
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
