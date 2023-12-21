import java.io.*;
import java.net.Socket;

public class Exam2 {
    public static void main(String[] args) throws IOException {
        String serverHost = "10.21.96.15"; 
        int serverPort = 807;

        try (Socket socket = new Socket(serverHost, serverPort)) {
            DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());

            String studentCode = "B20DCCN513";
            int qCode = 800;
            String requestData = studentCode + ";" + qCode;
            outputStream.writeUTF(requestData);

            DataInputStream inputStream = new DataInputStream(socket.getInputStream());

            int a = inputStream.readInt();
            int b = inputStream.readInt();

            int sum = a + b;
            int product = a * b;

            outputStream.writeInt(sum);
            outputStream.writeInt(product);

            socket.close();
        } catch (IOException e) {
        }
    }
}
